#include<iostream>
using namespace std;
void solve(int x){ 
    for(int i=1;i<=20;++i){
        for(int j=1;j<=20;++j){
            for(int k=1;k<=20;++k){
                for(int h=1;h<=20;++h){
                    if(i*h-j*k==x){ 
                        cout<<i<<" "<<j<<endl;
                        cout<<k<<" "<<h<<endl;
                        return ;
                    }
                }
            }
        }
    }
    cout<<-1<<endl;
}
int  main(){
    int x;
    cin>>x;
    solve(x);
    return 0;
}