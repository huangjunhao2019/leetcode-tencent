#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
template<typename Iterator,typename Value> auto find(Iterator first,Iterator last,Value const &value){
    for(;first!=last && *first!=value;++first);
    return first;
}
int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9};
    auto is_in_vector=v.end()!=find(v.begin(),v.end(),5);
    cout<<(is_in_vector?"found\n":"not found\n");
    list<string> l={"aa","bb","cc","dd","ee","ff","gg"};
    auto is_in_list=l.end()!=find(l.begin(),l.end(),"zz");
    cout<<(is_in_list?"found\n":"not found\n");
    
    return 0;
}