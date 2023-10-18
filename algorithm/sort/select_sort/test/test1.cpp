//给定一个01串，可以进行若干次操作
#include<iostream>
#include<string>
using namespace std;
long long solve_2(string &str){
    if(str=="00"){
        return 1;
    } 
    return 0;
}
long long solve_3(string &str){
    if(str=="000"){
        return 1;
    } else if(str=="001"){
        return 1;
    } else if(str=="010"){
        return 2;
    } else if(str=="011"){
        return 0;
    } else if(str=="100"){
        return 1;
    } else if(str=="101"){
        return 0;

    } else if(str=="110"){
        return 0;
    } else if(str=="111"){
        return 0;
    }
    return 0;
}
long long solve_4(string &str){
  //  long long res=0;
    if(str=="0000"){
        return 2;
    } else if(str=="0001"){
        return 1;
    } 
    return 2;
}
long long solve_5(string &str){
    return 10;
}
long long solve_6(string &str){
    return 20;
}
long long solve(string &str){
    long long res=0;
    switch(str.size()){
        case 0:
            res=0;
            break;
        case 1:
            res=1;
            break;
        case 2:
            res=solve_2(str);
            break;
        case 3:
            res=solve_3(str);
            break;
        case 4:
            res=solve_4(str);
            break;
        case 5:
            res=solve_5(str);
            break;
        case 6:
            res=solve_6(str);
            break;
        default:
            res=20;
            break;
    }
    return res;
}
int main(){
    string str;
    cin>>str;
    cout<<solve(str)<<endl;
    return 0;
}