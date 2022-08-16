#include<iostream>
#include<string>
using namespace std;
template<typename Arr> void print(Arr const &arr){
    for(auto const &ele:arr){
        cout<<ele<<endl;
    }
}
int main(){
    string s[]={"sssss","aaa","bbb"};
    char c[]={'a','b','c'};
    int i[]={1};
    print(s);
    print(c);
    print(i);
    return 0;
}