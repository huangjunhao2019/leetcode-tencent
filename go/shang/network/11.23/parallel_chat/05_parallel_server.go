package main

import (
	"fmt"
	"net"
	"strings"
)

type Client struct {
	C    chan string //用于发送数据的管道
	Name string      //用户名
	Addr string      //网络地址
}

// 保存在线用户
var onlineMap map[string]Client
var message = make(chan string)

func WriteMsgToClient(cli Client, conn net.Conn) {
	for msg := range cli.C {
		//给当前客户端发送信息
		conn.Write([]byte(msg + "\n"))
	}
}
func MakeMsg(cli Client, msg string) (buf string) {
	buf = "[" + cli.Addr + "]" + cli.Name + ": " + msg
	return

}
func HandleConn(conn net.Conn) {
	//获取客户端的网络地址
	cliAddr := conn.RemoteAddr().String()

	//创建一个结构体
	cli := Client{make(chan string), cliAddr, cliAddr}

	//把结构体加入到map
	onlineMap[cliAddr] = cli

	//新开一个协程，专门给当前客户端发送信息
	go WriteMsgToClient(cli, conn)
	//广播某个人在线
	//message <- "["+cli.Addr+"]"+cli.Name+": login"
	message <- MakeMsg(cli, "login")
	//提示我是谁
	cli.C <- MakeMsg(cli,"I am here")
	//新建一个协程，接收用户发送过来的数据
	isQuit := make(chan bool)
	go func(){
		buf := make([]byte,2048)
		for{
			n,err := conn.Read(buf)
			if n==0{//对方断开，或者出问题
				isQuit<-true
				fmt.Println("conn.Read err=",err)
				return 
			}
			//转发此内容
			msg := buf[:n-1] 
			if len(msg)==3 && string(msg)=="who"{
				//遍历map，给当前用户发送所有成员
				conn.Write([]byte("user list:\n"))
				for _,tmp := range onlineMap{
					tmpMsg := tmp.Addr+":"+tmp.Name+"\n"
					conn.Write([]byte(tmpMsg))
				}
			}else if len(msg)>=8 && string(msg[:6])=="rename"{
				name := strings.Split(string(msg),"|")[1]
				cli.Name=name
				onlineMap[cli.Addr]=cli

			} else{
				message <- MakeMsg(cli,string(msg))
			}
			
		}

	}()
	for {
		//通过select检测chan的流动
		select {
		case <- isQuit:
			delete(onlineMap,cliAddr)
			message<- MakeMsg(cli,"logout") //广播谁下线了
			return 
		}
	}

}
func Manager() {
	//给map分配空间
	onlineMap = make(map[string]Client)
	for {
		msg := <-message //没有消息时，会阻塞
		//遍历map，给map每个成员都发送此消息
		for _, cli := range onlineMap {
			cli.C <- msg
		}
	}
}
func main() {
	//监听
	listener, err := net.Listen("tcp", "127.0.0.1:8080")
	if err != nil {
		fmt.Println("net.Listen=", err)
		return
	}

	defer listener.Close()
	//新开一个协程，转发消息，只要有消息来了，遍历map，给map每个成员都发送此消息
	go Manager()
	//主协程，阻塞等待用户连接
	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("listener.Accept err=", err)
			continue
		}

		go HandleConn(conn) //处理用户连接

	}

}
