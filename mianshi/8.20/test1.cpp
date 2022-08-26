#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isOk(vector<vector<int>> &preSum,int i,int j){
    int rNum=preSum[j][0]-preSum[i][0];
    int eNum=preSum[j][1]-preSum[i][1];
    int dNum=preSum[j][2]-preSum[i][2];
    if(rNum==eNum && rNum==dNum){
        return true;
    }
    return false;
}
long long solve(string &s){
    int n=s.size();
    vector<vector<int>> preSum(n+1);
    int rNum=0;
    int eNum=0;
    int dNum=0;
    preSum[0]={0,0,0};
    for(int i=0;i<s.size();++i){
        if(s[i]=='r'){
            rNum++;
        }
        else if(s[i]=='e'){
            eNum++;
        }
        else{
            dNum++;
        }
        preSum[i+1]={rNum,eNum,dNum};
    }
    long long res=0;
    for(int i=0;i<s.size();++i){
        int j=i;
        while(j+3<=s.size()){
            if(isOk(preSum,i,j+3)){
                res++;
            }
            j+=3;
        }
    }
    return res;
}
/*void addNum(char ch,int &rNum,int &eNum,int &dNum,int value){
    if(ch=='r'){
        rNum+=value;
    }
    else if(ch=='e'){
        eNum+=value;
    }
    else{
        dNum+=value;
    }
}
long long solve2(string &s){
    int n=3;
    long long res=0;
    int rNum=0;
    int eNum=0;
    int dNum=0;
    while(n<=s.size()){
        //count.clear();
        rNum=0;
        eNum=0;
        dNum=0;
        for(int i=0;i<n-1;++i){
            addNum(s[i],rNum,eNum,dNum,1);
        }
        int left=0;
        for(int i=n-1;i<s.size();++i){
            addNum(s[i],rNum,eNum,dNum,1);
            if(rNum==eNum && rNum==dNum){
                cout<<"solve1 "<<left<<" "<<s.substr(left,n)<<endl;
                res++;
            }
            addNum(s[left],rNum,eNum,dNum,-1);
            ++left;
        }
        n+=3;
    }
    return res;
}

long long solve1(string &s){
    unordered_set<int> us;
    unordered_map<char,int> mp;
    long long res=0;
    for(int i=0;i<2;++i){
        mp[s[i]]++;
    }
    int left=0;
    for(int i=2;i<s.size();++i){
        mp[s[i]]++;
        if(mp['r']==mp['e'] && mp['r']==mp['d']){
            us.insert(left);
        }
        mp[s[left]]--;
        ++left;
    }
    for(auto num:us){
        cout<<"us: "<<num<<endl;
    }
    for(int i=0;i<s.size();++i){
        if(us.count(i)==1){
            int j=i;
            while(j<s.size() && us.count(j)==1){
                cout<<i<<" "<<j<<" "<<s.substr(i,j-i)<<endl;
                j+=3;
            }
            cout<<i<<" "<<j<<" "<<s.substr(i,j-i)<<endl;
            int len=(j-i)/3;
            res+=len;
        }
    }
    return res;
}*/
int main(){
    string s;
    cin>>s;
    long long res=solve(s);
    cout<<res<<endl;
     
    return 0;
}