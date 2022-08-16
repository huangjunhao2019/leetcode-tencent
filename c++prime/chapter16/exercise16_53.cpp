#include<iostream>
using namespace std;
template<typename Printable> ostream &print(ostream &os,Printable const &printable){
    return os<<printable;
}
template<typename Printable,typename... Args> ostream &print(ostream &os,Printable const &printable,Args const &... rest){
    os<<printable<<",";
    return print(os,rest...);
}
int main(){
    print(cout,1)<<endl;
    print(cout,1,2)<<endl;
    print(cout,1,2,3,4)<<endl;
    return 0;
}