#include<iostream>
#include<vector>
#include<list>
using namespace std;
template<typename Container> ostream &print(Container const &container,ostream &os){
    for(typename Container::size_type i=0;i!=container.size();++i){
        os<<container[i]<<" ";
    }
    return os;
}
template<typename Container> ostream &print2(Container const &container,ostream &os){
    for(auto curr=container.begin();curr!=container.end();++curr){
        os<<*curr<<" ";
    }
    return os;
}
int main(){
    vector<int> v={1,23,6,4,5};
    list<string> l={"ss","aa","bb"};
    print(v,cout)<<endl;
    print2(l,cout)<<endl;
    return 0;
}