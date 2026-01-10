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
    int findHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = findHeight(root->left);
        int right = findHeight(root->right);
        return max(left,right)+1;
    }
public:
    int maxDepth(TreeNode* root) {

        int ans = findHeight(root);
        return ans;
    }
};