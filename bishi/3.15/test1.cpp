#include<iostream>
#include<unordered_map>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};
int main(){
    int n;
    cin>>n;
    unordered_map<int,TreeNode *> treeMp;
    TreeNode *root=new TreeNode();
    treeMp[1]=root;
    for(int i=1;i<=n;++i){
        int leftVal=0;
        int rightVal=0;
        cin>>leftVal>>rightVal;
        if(leftVal!=-1){
            TreeNode *leftNode=new TreeNode(leftVal);
            treeMp[i]->left=leftNode;
            treeMp[leftVal]=leftNode;
        }
        if(rightVal!=-1){
            TreeNode *rightNode=new TreeNode(rightVal);
            treeMp[i]->right=rightNode;
            treeMp[rightVal]=rightNode;
        }
    }
    
}