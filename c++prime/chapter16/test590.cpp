#include<iostream>
#include<vector>
using namespace std;
int main(){
    typedef pair<int,int> p;
    vector<p> vec={{1,2},{3,4}};
    for(auto it=vec.begin();it!=vec.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
