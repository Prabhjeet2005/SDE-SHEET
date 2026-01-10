#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val){
    this->val = val;
    left = nullptr;
    right = nullptr;
  }
};

class Solution{
  TreeNode* create_tree(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    return root;
  }
  public:
  void find_level_order(){
    TreeNode* root = create_tree();

    queue<TreeNode*>q;
    vector<int>level_order;
    if(!root)return;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
      int size = q.size();

      for(int i=0; i<size; i++){}
        TreeNode* front = q.front();
        q.pop();
        if(front){
          level_order.push_back(front->val);
          if(front->left){
            q.push(front->left);
          }
          if(front->right){
            q.push(front->right);
          }
        }else{
          // nullptr
          if(!q.empty()){
            q.push(nullptr);
          }
        }

    }

    for(auto & el: level_order){
      cout<<el<<" ";
    }

  }
};

int main(){
  Solution sol_obj = Solution();
  cout<<"\n";
  sol_obj.find_level_order();
  cout<<"\n";

}