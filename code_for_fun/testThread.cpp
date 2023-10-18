#include<iostream>
#include<thread>
using namespace std;

int i=0;
void test(){
    int num=10000;
    for(int n=0;n<num;n++){
        i+=1;
    }
}
int main(){
    cout<<"Start all threads."<<endl;
    thread thread_test1(test);
    thread thread_test2(test);

    thread_test1.join();
    thread_test2.join();
    cout<<"All threads joined."<<endl;
    cout<<"now i is "<<i<<endl;
    return 0;
}