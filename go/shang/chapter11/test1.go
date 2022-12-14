package main

import "fmt"
type Account struct{
	AccountNo string
	Pwd string
	Balance float64
}
//方法
//1.存款
func (account *Account) Deposite(money float64,pwd string){
	if pwd != account.Pwd{
		fmt.Println("你输入的密码不正确")
		return 
	}
	//看看存款金额是否正确
	if money<=0{
		fmt.Println("你输入的金额不正确")
		return 
	}
	account.Balance+=money
	fmt.Println("存款成功~~~")
}
//2. 取款
func (account *Account) WithDraw(money float64,pwd string){
	if pwd != account.Pwd{
		fmt.Println("你输入的密码不正确")
		return 
	}
	//看看存款金额是否正确
	if money<=0 || money>account.Balance{
		fmt.Println("你输入的金额不正确")
		return 
	}
	account.Balance-=money
	fmt.Println("取款成功~~~")
}
//3.查询余额
func (account *Account) Query(pwd string){
	if pwd != account.Pwd{
		fmt.Println("你输入的密码不正确")
		return 
	}
	
	fmt.Printf("你的账号=%v，余额为%v\n",account.AccountNo,account.Balance)
}
func main(){
	account := &Account{
		AccountNo: "gong111",
		Pwd:"666666",
		Balance: 100,
	}
	account.Query("666666")
}