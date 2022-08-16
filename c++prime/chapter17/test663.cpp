#include<ctime>
#include<iostream>
#include<random>
using namespace std;
int main(){
    time_t currentTime=time(nullptr);
    cout<<currentTime/(365*24*60*60)<<endl;
    return 0;
}