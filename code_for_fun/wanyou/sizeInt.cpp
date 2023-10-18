#include<iostream>
using namespace std;

struct st{
    int *p;
    int i;
    char a;
};
int main(){
    int sz=sizeof(struct st);
    cout<<sz<<endl;
    return 0;
}