#include<iostream>
#include<cstring>
using namespace std;
void size_of(char arr[]){
    cout<<sizeof arr<<endl;
    cout<<strlen(arr)<<endl;
}
int main(){
    char arr[20]="hello";
    size_of(arr);
    cout<<sizeof(int)<<endl;
    return 0;
}