#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class Solution {
public:

    /* Write Code Here */
    vector < int > calculateFinalPositi(string ins) {
        unsigned long long Lnum=0;
        unsigned long long Rnum=0;
        unsigned long long Unum=0;
        unsigned long long Dnum=0;
        for(auto &ch:ins){
            if(ch=='L'){
                Lnum++;
            } else if(ch=='R'){
                Rnum++;
            } else if(ch=='U'){
                Unum++;
            } else if(ch=='D'){
                Dnum++;
            }
        }
        int row=(long long)Rnum-(long long)Lnum;
        int col=(long long)Unum-(long long)Dnum;
        return {row,col};
    }
};
int main() {
    vector < int > res;

    string instructions;
    getline(cin, instructions);
    Solution *s = new Solution();
    res = s->calculateFinalPositi(instructions);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    return 0;

}
