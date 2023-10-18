package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
)

type signUpReq struct{
	Email	string `json:"email"`
	Password string `json:"password"`
	ConfirmedPassword string `json:"confirmed_password"`
}
type commonResponse struct{
	Msg string `json: "msg"`
	Data interface{} `json:"data"`
}
func home(w http.ResponseWriter,r *http.Request){
	fmt.Fprintf(w,"这是主页")
}
func signUp(w http.ResponseWriter, r *http.Request){
	req := &signUpReq{}

	body,err := io.ReadAll(r.Body)
	if err!=nil{
		fmt.Fprintf(w,"read body failed: %v",err)
		return 
	}
	err = json.Unmarshal(body,req)
	if err!=nil{
		fmt.Fprintf(w,"deserialized failed: %v",err)
		return 
	}
	fmt.Printf("Log-Req-%v",req)

	resp := &commonResponse{
		Msg: "Success",
		Data: "Sign up successful",
	}
	respJson, _ := json.Marshal(resp)
	fmt.Fprintf(w,string(respJson))
}

func main(){
	http.HandleFunc("/",home)
	http.HandleFunc("/signup",signUp)
	http.ListenAndServe(":8080",nil)
}