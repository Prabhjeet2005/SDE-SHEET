/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        
        int mid = -1;
        for(int i=0; i<inorder.size(); i++){
            if(preorder[0] == inorder[i] ){mid = i;break;}
        }
        if(mid == -1)return nullptr;

        vector<int>left_inorder(inorder.begin(),inorder.begin()+mid);
        vector<int>right_inorder(inorder.begin()+mid+1,inorder.end());
        vector<int>left_preorder(preorder.begin()+1,preorder.begin()+left_inorder.size()+1);
        vector<int>right_preorder(preorder.begin()+left_inorder.size()+1,preorder.end());

        root->left = buildTree(left_preorder,left_inorder);
        root->right = buildTree(right_preorder,right_inorder);
        return root;
    }
};