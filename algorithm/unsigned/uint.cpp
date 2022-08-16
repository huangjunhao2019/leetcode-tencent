#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a={1,2,3,4,5,6};
    vector<int> b={1,2,3,4,5,6,7,8,9};
    
    for(int i=0;i<b.size()-a.size();++i){
        cout<<-1<<endl;
    }
    return 0;
}