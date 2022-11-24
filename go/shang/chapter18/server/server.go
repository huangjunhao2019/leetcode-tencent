package main
import (
	"fmt"
	"net" //做网络开发时，net包含我们需要的所有方法和函数
	_"io"
) 
func process(conn net.Conn){
	//这里我们循环接收客户端发送的数据
	defer conn.Close()
	
	 for{
		//创建一个新的切片
		buf := make([]byte,512)
		//1. 等待客户端通过conn发送信息
		//2. 如果客户端没有write，那么协程一直阻塞
		//fmt.Println("服务器在等待客户端发送信息",conn.RemoteAddr().String())
		n,err := conn.Read(buf) //从conn读取
		if err!=nil  {
			// if err==io.EOF{
			// 	return
			// }
			fmt.Println("服务器的Read err=",err)
			return
		}  
		//3. 显示客户端发送的内容到服务器的终端
		fmt.Print(string(buf[0:n]))  
	 }
}
func main(){
	fmt.Println("服务器开始监听...")
	//1. tcp表示使用网络协议是tcp
	//2. 0.0.0.0:8888表示在本地监听8888端口
	listen,err := net.Listen("tcp","127.0.0.1:8888")
	if err!=nil{
		fmt.Println("listen err=",err) 
	}
	defer listen.Close() //延时关闭listen

	//等待客户端来连接
	for{
		//等待客户端来连接
		fmt.Println("等待客户端来连接")
		conn,err := listen.Accept()
		if err!=nil{
			fmt.Println("Accept() err=",err)
			break
		} else{
			fmt.Printf("Accept() suc con=%v 客户端ip=%v\n",conn,conn.RemoteAddr().String())
		}
		go process(conn)
		 
	}
	fmt.Println("listen=",listen)
}