#include<iostream>
#include<string>

using namespace std;
long long solve(long long num){
    string numStr=to_string(num);
    string evenNum="";
    string oddNum="";
    for(auto &ch:numStr){
        int temp=ch-'0';
        if(temp%2==0){
            evenNum+=ch;
        } else{
            oddNum+=ch;
        }
    }
    return abs(stoi(evenNum)-stoi(oddNum));
}
int main(){
    long long num;
    cin>>num;
    cout<<solve(num)<<endl;
    return 0;
}