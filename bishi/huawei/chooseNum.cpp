#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
// int choose(int n,int m){
//     vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
//     for(int i=0;i<=n;++i){
//         for(int j=0;j<=i;++j){
//             if(j==0){
//                 dp[i][j]=1;
//                 continue;
//             }
//             dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
//         }
//     }
//     return dp[n][m];
// }

// int choose2(int n,int m){
//     int fn=1;
//     int fm=1;
//     for(int i=1;i<=m;++i){
//         fm*=i;
//         fn*=n-i+1;
//     }
//     return fn/fm;
// }
// int main(){
//     int n;
//     int m;
//     while(cin>>n>>m){
//         cout<<choose(n,m)<<endl;
//         cout<<choose2(n,m)<<endl;
//     }
//     return 0;
// }
class A{};
int main()
{
    // vector<int> v = {3,9,1,4,2,5,9,0};
    // auto res = minmax_element(v.cbegin(), v.cend());
    // cout << *res.first << " " << *res.second << endl;
    // return 0;
    // const int c1 = 1;
    // const int &p1 = c1;
    // p1= 0;
    // int &p2 = c1;
    // const int &p3 = 2;
    // int & p4 = p3 * 2;
    // int x = 5;
    // int y = 4;
    // x = x << 2;
    // y = y >> 2;
    // cout << x << endl;
    // cout << y << endl;
    cout << sizeof(A) << endl;
    return 0;
}