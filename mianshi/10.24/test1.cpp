#include<iostream>
#include<unordered_set>
using namespace std;
bool isOk(int n,int m){ 
    unordered_set<int> us;
    for(int i=1;i<=m;++i){
        int temp=n%i;
        if(us.find(temp)!=us.end()){
            return true;
        }
        us.insert(temp);
    }
    return false;
}
int main(){
    int count;
    cin>>count;
    int n;
    int m;
    for(int i=0;i<count;i++){
        cin>>n;
        cin>>m;
        if(isOk(n,m)){
            cout<<"Yes"<<endl;
        } else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
