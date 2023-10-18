#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void reverseWord(string &str){
    int left=0;
    int right=0;
    while(left<str.size() && right<str.size()){
        while(left<str.size() && !(str[left]>='a' && str[left]<='z' || str[left]>='A' && str[left]<='Z')){
            ++left;
        }
        right=left;
        while(right<str.size() && (str[right]>='a' && str[right]<='z' || str[right]>='A' && str[right]<='Z')){
            ++right;
        }
        reverse(str.begin()+left,str.begin()+right);
        left=right;
    }
    
}
int main(){
    string str="hello world";
    reverseWord(str);
    cout<<str<<endl;
    return 0;
}