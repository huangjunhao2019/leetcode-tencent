#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    string s="some string";
    for(int i=0;i<s.size() && s[i]!=' ';i++){
        s[i]=toupper(s[i]);
    }
    cout<<s<<endl;
    return 0;
}
