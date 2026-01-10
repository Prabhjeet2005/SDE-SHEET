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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return calculate_inorder(root,prev);
    }
    private:
    bool calculate_inorder(TreeNode*& root,TreeNode* &prev){
        if(!root)return true;
        bool left = calculate_inorder(root->left,prev);
        if(prev && prev->val >= root->val)return false;
        prev = root;
        bool right = calculate_inorder(root->right,prev);
        return left & right;
    }
};