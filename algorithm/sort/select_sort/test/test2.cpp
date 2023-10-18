//ali型字符串
#include<iostream>
#include<string>
using namespace std;
string solve(string &str){
    int n=str.size();
    if((str[0]!='a' && str[0]!='A') || (str[n-1]!='i' && str[n-1]!='I')){
        return "No";
    }
    int left=0;
    int right=n-1;
    while(left<right && (str[left]=='a' || str[left]=='A')){
        ++left;
    }
    while(left<right && (str[right]=='i' || str[right]=='I')){
        --right;
    }
    if(left>right){
        return "No";
    }
    for(int i=left;i<=right;++i){
        if(str[i]!='l' && str[i]!='L'){
            return "No";
        }
    }
    return "Yes";
}
int main(){
    int t;
    cin>>t;
    string str;
    for(int i=0;i<t;++i){
        cin>>str;
        cout<<solve(str)<<endl;
    }
    return 0;
}