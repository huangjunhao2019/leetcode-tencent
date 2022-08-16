#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;
int main(){
    vector<int> nums(10,0);
    int a=10;
    double b=1;
    cout<<typeid(nums).name()<<" "<<typeid(a).name()<<" "<<typeid(b).name()<<endl;
    return 0;
}