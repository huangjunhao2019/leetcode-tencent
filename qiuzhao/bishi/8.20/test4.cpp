#include<iostream>
#include<vector>
using namespace std;
class ListNode{
public:
    int a;
    int b;
    ListNode(int c,int d):a(c),b(d){}
};
int main(){
    vector<ListNode> vec={ListNode(0,0),ListNode(1,1)};
    for(int i=0;i<vec.size();++i){
        cout<<vec[i].a<<" "<<vec[i].b<<endl;
    }
    return 0;
}