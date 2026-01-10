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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;

        bool same_check = is_same(root,subRoot);
        if(same_check)return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    private:
    bool is_same(TreeNode*root,TreeNode*sub_root){
        if(!root && !sub_root)return true;

        if(( !root && sub_root ) || (root && !sub_root))return false;

        if(root->val != sub_root->val)return false;

        bool left = is_same(root->left,sub_root->left);
        bool right = is_same(root->right, sub_root->right);

        return left && right; // This important [Both must give true for tree to be identical]
    }
};