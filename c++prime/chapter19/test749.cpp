#include<iostream>
using namespace std;
union Token{
    char cval;
    int ival;
    double dval;
};
int main(){
    Token firstToken={'a'};
    cout<<sizeof(firstToken)<<endl;
    return 0;
}