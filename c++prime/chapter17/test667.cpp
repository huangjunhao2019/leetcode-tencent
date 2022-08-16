#include<iostream>
using namespace std;
int main(){
    cout<<"default bool values: "<<true<<" <<false"
    <<"\nalpha bool values: "<<boolalpha<<true<<" "<<false<<endl;
    cout<<noboolalpha<<true<<" "<<false<<endl;
    cout<<"default: "<<20<<" "<<1024<<endl;
    cout<<"octal: "<<oct<<20<<" "<<1024<<endl;
    cout<<"hex: "<<hex<<20<<" "<<1024<<endl;
   // cout<<"decimal: "<<dec<<20<<" "<<1024<<endl;
    cout<<20<<" "<<1024<<endl;
    return 0;
}