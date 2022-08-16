#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    cin>>noskipws;
    char ch;
    while(cin>>ch){
        if(ch=='!'){
            break;
        }
        cout<<ch;
    }
    cin>>skipws;
    while(cin>>ch){
        cout<<ch;
    }
    return 0;
}