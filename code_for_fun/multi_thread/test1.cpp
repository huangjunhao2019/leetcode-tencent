#include<iostream>
#include<thread>
using namespace std;
void test1(){
    for(int i=0;i<10;++i){
        cout<<"test1()";
    }
}
void test2(){
    for(int i=0;i<10;++i){
        cout<<"test2()";
    }
}
int main(){
    thread thread_test1(test1);
    thread thread_test2(test2);

    thread_test1.join();
    thread_test2.join();
    cout<<"main Thread"<<endl;
    return 0;
}