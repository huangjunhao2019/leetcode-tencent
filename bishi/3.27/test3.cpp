#include<iostream>
#include<vector>
#include<climits>
#include<unordered_set>
using namespace std;
int res;
vector<int> path;
bool isOk(vector<int> &path,vector<int> &B){
    for(int i=0;i<path.size();++i){
        for(int j=i+1;j<path.size();++i){
            if(B[i]>B[i]){
                if(!(path[i]>path[j])){
                    return false;
                }
            }
        }
    }
    return true;
}
int cal(vector<int> &path,vector<int> &A){
    int res=0;
    for(int i=0;i<path.size();++i){
        res+=abs(path[i]-A[i]);
    }
    return res;
}
void backTrack(vector<int> &A,vector<int> &B,int start,int n,unordered_set<int> &us){
    if(path.size()==n){
        if(isOk(path,A)){
            res=min(res,cal(path,A));
        }
        return ;
    }
    for(int i=start;i<=n;++i){
        if(us.count(i)==1){
            continue;
        }
        us.insert(i);
        path.push_back(i);
        backTrack(A,B,start,n,us);
        us.erase(i);
        path.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);
    for(int i=0;i<n;++i){
        cin>>A[i];
        cin>>B[i];
    }
    unordered_set<int> us;
    res=INT_MAX;
    backTrack(A,B,1,n,us);
    cout<<res<<endl;
    return 0;
}