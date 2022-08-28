#include<iostream>
using namespace std;
int main(){
    double res=0;
    for(double x=-100;x<=100;x+=0.1){
        for(double y=-100;y<=100;y+=0.1){
            if(5*x+3*y<=1 && y<=x+1 && x-5*y<=3){
                res=max(res,3*x+5*y);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
