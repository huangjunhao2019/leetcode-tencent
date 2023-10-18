#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int mod=1e9+7;
int main(){
    int n,k;
    cout<<gcd(12,8)<<endl;
    cin>>n>>k;
    vector<int> nums;
   // nums.reserve(n);
    int temp;
    for(int i=0;i<n;++i){
        cin>>temp;
        cout<<"temp1 "<<temp<<endl;
        if(temp%k==0){
            nums.push_back(temp);
            cout<<"temp2 "<<temp<<endl;
        }
    }
    sort(nums.begin(),nums.end());
    long long res=0;
    for(int i=0;i<nums.size();++i){
        for(int j=i;j<nums.size();++j){
            if(gcd(nums[i],nums[j])==k){
                res=(res+(long long)pow(2,nums.size()-1-j))%mod;
                break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
