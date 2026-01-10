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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        int ans = max(l,r)+1;

        return ans;
        
    }
public:
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};