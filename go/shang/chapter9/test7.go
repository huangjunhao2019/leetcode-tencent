package main

import "fmt"

func modifyUser(users map[string]map[string]string,name string){
	if users[name]!=nil{ //这儿和cpp有点不一样，不会自动创建空的
		users[name]["pwd"]="888888"
	} else{
		users[name]=make(map[string]string,2)
		users[name]["pwd"]="888888"
		users[name]["nickname"]="昵称~"+name
	}
}
func main(){
	users := make(map[string]map[string]string,10)
	users["smith"]=make(map[string]string)
	users["smith"]["pwd"]="999999"
	users["smith"]["nickname"]="小花猫"
	modifyUser(users,"tom")
	modifyUser(users,"mary")
	modifyUser(users,"smith")
	fmt.Println(users)
}