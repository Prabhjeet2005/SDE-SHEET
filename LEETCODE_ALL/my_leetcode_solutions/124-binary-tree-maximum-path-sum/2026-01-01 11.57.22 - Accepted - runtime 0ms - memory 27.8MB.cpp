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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN,curr_sum = 0;
        curr_sum = calculate_sum(root,max_sum);
        return max_sum;
    }
    private:
    int calculate_sum(TreeNode* root,int &max_sum){
        if(!root)return 0;
        int left_sum = calculate_sum(root->left,max_sum);
        int right_sum = calculate_sum(root->right,max_sum);
        if(left_sum < 0)left_sum = 0;
        if(right_sum < 0)right_sum = 0;
        max_sum = max(max_sum,left_sum + right_sum + root->val);
        return root->val + max(left_sum,right_sum); // THis IMPORTANT
    }
};