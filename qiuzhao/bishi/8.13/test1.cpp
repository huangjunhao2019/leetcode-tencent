#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<algorithm>

using namespace std;

class Solution {
public:

    /* Write Code Here */
    vector<int> res;
    vector<int> path;
    void backTrack(vector<int> &nums,vector<int> &used,int n){
        if(path.size()==3){
            res.push_back(path[0]*100+path[1]*10+path[2]);
            return ;
        }
        for(int i=0;i<n;++i){
            if(used[i]==1){
                continue;
            }
            used[i]=1;
            path.push_back(nums[i]);
            backTrack(nums,used,n);
            path.pop_back();
            used[i]=0;
        }
    }
    vector < int > ThreeDigitNumbers (vector < int > selectedDigits) {
        sort(selectedDigits.begin(),selectedDigits.end());
        int n=selectedDigits.size();
        vector<int> used(n,0);
        backTrack(selectedDigits,used,n);
        return res;
    }
};
int main() {
    vector < int > res;

    int selectedDigits_size = 0;
    cin >> selectedDigits_size;

    vector<int> selectedDigits;
    int selectedDigits_item;
    for(int selectedDigits_i=0; selectedDigits_i<selectedDigits_size; selectedDigits_i++) {
        cin >> selectedDigits_item;

        selectedDigits.push_back(selectedDigits_item);
    }


    Solution *s = new Solution();
    res = s->ThreeDigitNumbers (selectedDigits);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    return 0;

}
