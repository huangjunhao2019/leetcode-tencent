#include<iostream>
#include<tuple>
using namespace std;
int main(){
    auto item=make_tuple("0-999-78345-X",3,20.00);
    auto book=get<0>(item);
    auto cnt=get<1>(item);
    auto price=get<2>(item);
    cout<<book<<" "<<cnt<<" "<<price<<endl;
    get<2>(item)*=0.8;
    cout<<get<0>(item)<<" "<<get<1>(item)<<" "<<get<2>(item)<<endl;
    return 0;
}