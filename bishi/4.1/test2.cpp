#include<iostream>
#include<cmath>
using namespace std;
double solve(double a){
    return floor((a+0.05)*10)/10;
}
int main(){
    double a;
    cin>>a;
    printf("%.1f\n",solve(a));
    return 0;
}