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
        return check_balanced(root).is_height_balanced;
    }
    struct Balance{
        int height;
        bool is_height_balanced;
    };
    private:
    Balance check_balanced(TreeNode* root){
        if(!root)return {0,true};
        Balance left = check_balanced(root->left);
        Balance right = check_balanced(root->right);

        bool is_balanced = left.is_height_balanced && right.is_height_balanced && abs(left.height - right.height)<=1;

        return {max(left.height,right.height)+1,is_balanced};
    }
};