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
    bool isBalanced(TreeNode* root) {
        return check_balanced(root).second;
    }
    private:
    pair<int,bool> check_balanced(TreeNode* root){
        if(!root)return {0,true};
        pair<int,bool> left = check_balanced(root->left);
        pair<int,bool> right = check_balanced(root->right);

        bool is_balanced = left.second && right.second && abs(left.first - right.first)<=1;

        return {max(left.first,right.first)+1,is_balanced};
    }
};