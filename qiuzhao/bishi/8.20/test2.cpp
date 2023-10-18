/*
input:
2 2 1 2
output:
2 2 8.0

input:
2 3 1 2
output:
4 2 18.1
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


unordered_map<int,double> mp;
unordered_map<int,int> countMp;
vector<vector<int>> direc={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
void calculate(vector<vector<char>> &grid,int n,int m,int c,int dd,int countA,int countB){
    double res=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='B'){
                double tempRes=c;
                for(auto &d:direc){
                    int newRow=i+d[0];
                    int newCol=j+d[1];
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m){
                        if(grid[newRow][newCol]=='A'){
                            tempRes=tempRes*(double)dd;
                        }
                    }
                }
                res+=tempRes;
            }
        }
    }
    mp[countA*100+countB]+=res;
    countMp[countA*100+countB]++;
}
void backTrack(vector<vector<char>> &grid,int n,int m,int c,int d,int countA,int countB,int row,int col){
    if(countA+countB>=n*m){
        calculate(grid,n,m,c,d,countA,countB);
        return ;
    }
    if(row>=n){
        return ;
    }
    if(col>=m){
        row++;
        col=0;
    }
    grid[row][col]='A';
    backTrack(grid,n,m,c,d,countA+1,countB,row,col+1);
    grid[row][col]='B';
    backTrack(grid,n,m,c,d,countA,countB+1,row,col+1);
}
double sheRu(double res){
    long long point2num=(long long)(res*100)%10;
    if(point2num>=5){
        res+=0.1;
    }
    return res;
}
int main(){
    int n,m,c,d;
    cin>>n>>m>>c>>d;
    vector<vector<char>> grid(n,vector<char>(m,'C'));
    int countA=0;
    int countB=0;
    backTrack(grid,n,m,c,d,countA,countB,0,0);
    int resA=1000;
    int resB=1000;
    double res=0;
    //处理map
    for(auto it=mp.begin();it!=mp.end();it++){
        int initNum=it->first;
        // double sum=0;
        // for(auto &num:it->second){
        //     sum+=num;
        // }
        // sum/=(it->second).size();
        double sum=it->second/countMp[initNum];
        if(sum>res){
            resA=initNum/100;
            resB=initNum%100;
            res=sum;
        } else if(sum==res){
            if(initNum/100<resA){
                resA=initNum/100;
                resB=initNum%100;
                res=sum;
            }
        } else{
            continue;
        }
    }
    //res=sheRu(res);
    printf("%d %d %.1lf\n",resA,resB,res);
   // cout<<resA<<" "<<resB<<" "<<res<<endl;
    return 0;
}