#include<iostream>
using namespace std;
struct stu{
    string name;
    int stuNo;
    stu():name(""),stuNo(0){}
    stu(string _name,int _stuNo):name(_name),stuNo(_stuNo){}
};
int main(){
    stu *a=new stu("huang",123);
    cout<<a->name<<endl;
    return 0;
}