#include<iostream>
#include<string>
using namespace std;
string add_pre_and_suffix(string &name,const string &pre,const string &su){
    name.insert(name.begin(),pre.begin(),pre.end());
    name.append(su);
    return name;
}
int main(){
    string name("Huang");
    cout<<add_pre_and_suffix(name,"Mr."," Jr.")<<endl;
    return 0;
}