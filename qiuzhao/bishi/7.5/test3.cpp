#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
const int maxVal=100000;
vector<int> kVecX={1,-1};
vector<int> kVecY={1,-1};
vector<vector<int>> horse={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int solve(int x1,int y1,int x2,int y2){
    int x=abs(x1-x2);
    int y=abs(y1-y2);
    vector<vector<int>> matrix(x+10,vector<int>(y+10,maxVal));
    queue<pair<int,int>> que;
    unordered_set<string> visit;
    que.push({0,0});
    matrix[0][0]=0;
    visit.insert("0,0");
    while(!que.empty()){
        auto temp=que.front();
        que.pop();
        if(temp.first==x && temp.second==y){
            return matrix[x][y];
        }
        int count=matrix[temp.first][temp.second];
        int tX=temp.first;
        int tY=temp.second;
        for(int k=0;k<=x;++k){
            for(int i=0;i<2;++i){
                for(int j=0;j<2;++j){
                    int newKX=k*kVecX[i];
                    int newKY=k*kVecY[j];
                    if(tX+newKX>=0 && tX+newKX<x+10 && tY+newKY>=0 && tY+newKY<y+10){
                        matrix[tX+newKX][tY+newKY]=min(matrix[tX+newKX][tY+newKY],count+1);
                        // if(tX+newKX==x && tY+newKY==y){
                        //     return matrix[tX+newKX][tY+newKY];
                        // }
                        string newXYK=to_string(tX+newKX)+","+to_string(tY+newKY);
                        if(visit.find(newXYK)==visit.end()){
                            que.push({tX+newKX,tY+newKY});
                            visit.insert(newXYK);
                        }
                    }
                }
            }
        }
        for(auto &h:horse){
            int newXH=h[0]+tX;
            int newYH=h[1]+tY;
            if(newXH>=0 && newXH<x+10 && newYH>=0 && newYH<y+10){
                matrix[newXH][newYH]=min(matrix[newXH][newYH],count+1);
                // if(newXH==x && newYH==y){
                //     return matrix[newXH][newYH];
                // }
                string newXYH=to_string(newXH)+","+to_string(newYH);
                if(visit.find(newXYH)==visit.end()){
                    que.push({newXH,newYH});
                    visit.insert(newXYH);
                }
            }
        }
    }
    return 0;
}
int main(){
    int x1,y1,x2,y2;
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>x1>>y1>>x2>>y2;
        cout<<solve(x1,y1,x2,y2)<<endl;
    }
    return 0;
}