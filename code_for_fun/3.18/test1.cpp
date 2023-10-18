#include<iostream>
#include<string>
using namespace std;
void solve(string &str){
    int n=str.size();
    int left=0;
    int right=n-1;
    while(left<right){
        if(str[left]!=str[right]){
            str[left]='a';
            str[right]='a';
            break;
        }
        if(str[left]==str[right] && str[left]>'a'){
            str[left]='a';
            str[right]='a';
            break;
        }
        ++left;
        --right;
    }
}
int main(){
    string str;
    cin>>str;
    solve(str);
    cout<<str<<endl;
    return 0;
}