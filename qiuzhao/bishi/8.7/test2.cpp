#include<iostream>
#include<string>
#include<vector>
using namespace std;
string coupons(string &s){
    string res="";
    vector<int> chNums(26,0);
    for(auto &ch:s){
        chNums[ch-'a']++;
    }
    for(int i=0;i<26;++i){
        if(chNums[i]>0){
            res.push_back(i+'a');
            --chNums[i];
        }
    }
    for(int i=25;i>=0;--i){
        while(chNums[i]>0){
            res.push_back(i+'a');
            chNums[i]--;
        }
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    cout<<coupons(s)<<endl;
    return 0;
}