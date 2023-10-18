/*
input:
4 1
2 3 4 5
output:
3.5000000
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    long long sum=0;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        sum+=temp;
    }
    double res=double(sum)/(4*x);
    cout<<res<<endl;
    return 0;
}