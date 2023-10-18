#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
 	int val;
 	struct TreeNode *left;
  	struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
    vector<TreeNode*> res;
    TreeNode *root=new TreeNode(preOrder[0]);
    int spideLoc=0;
    for(int i=0;i<inOrder.size();i++){
        if(inOrder[i]==root->val){
            spideLoc=i;
            break;
        }
    }
    vector<int> leftPreOrder(preOrder.begin()+1,preOrder.begin()+spideLoc
}
void levelOrder(TreeNode *node){
    if(node==nullptr){
        return ;
    }
    queue<TreeNode *> que;
    que.push(node);
    cout<<node->val<<endl;
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++){
            TreeNode *temp=que.front();
            que.pop();
            if(temp->left!=nullptr){
                cout<<temp->left->val<<" ";
                que.push(temp->left);
            } else{
                cout<<"nullptr ";
            }
            if(temp->right!=nullptr){
                cout<<temp->right->val<<" ";
                que.push(temp->right);
            } else{
                cout<<"nullptr ";
            }
        }
    }
}
int main(){
    vector<int> preOrder;
    vector<int> inOrder;
    int m;
    int n;
    while(true){
        cin>>m;
        cin>>n;
        for(int i=0;i<m;i++){
            int val;
            cin>>val;
            preOrder.push_back(val);
        }
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            inOrder.push_back(val);
        }
        vector<TreeNode*> res=getBinaryTrees(preOrder,inOrder);
        for(auto &tree:res){
            levelOrder(tree);
        }
        return 0;
    }
}