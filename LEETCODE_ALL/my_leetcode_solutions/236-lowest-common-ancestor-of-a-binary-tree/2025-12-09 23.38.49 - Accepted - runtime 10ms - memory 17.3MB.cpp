/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;
        if(root == p || root == q)return root;

        TreeNode* left_tree = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_tree = lowestCommonAncestor(root->right,p,q);

        if(left_tree && right_tree)return root;
        if(left_tree && !right_tree){
            // In Left Part
            return left_tree;
        }
        if(right_tree && !left_tree){
            // in right part
            return right_tree;
        }

        return nullptr;
    }
};