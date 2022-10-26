#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int res=0;
int tempValue=0;
unordered_set<int> occupy;
unordered_map<int,unordered_set<int>> mp;
bool isOk(int index){
    for(auto &num:mp[index]){
        if(occupy.find(num)!=occupy.end()){
            return false;
        }
    }
    return true;
}
void backTrack(vector<int> &tree,vector<int> &radius,vector<int> &value,int start){
    if(start>=value.size()){
        res=max(res,tempValue);
        return ;
    }
    for(int i=start;i<value.size();++i){
        if(isOk(i)){
            occupy.insert(i);
            tempValue+=value[i];
            res=max(res,tempValue);
            backTrack(tree,radius,value,i+1);
            tempValue-=value[i];
            occupy.erase(i);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> tree(n,0);
    for(int i=0;i<n;++i){
        cin>>tree[i];
    }
    vector<int> radius(n,0);
    for(int i=0;i<n;++i){
        cin>>radius[i];
    }
    vector<int> value(n,0);
    for(int i=0;i<n;++i){
        cin>>value[i];
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;j++){
            if(!(tree[i]+radius[i]<=tree[j]-radius[j] || tree[i]-radius[i]>=tree[j]+radius[j])){
                mp[i].insert(j);
                mp[j].insert(i);
            }
        }
    }
    backTrack(tree,radius,value,0);
    cout<<res<<endl;
    return 0;
}