/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr_path;
        long long curr_sum = 0;
        get_target_path(root, targetSum, curr_sum, curr_path, ans);

        return ans;
    }

private:
    void get_target_path(TreeNode*& root, int targetSum, long long curr_sum,
                         vector<int>& curr_path, vector<vector<int>>& ans) {

        if (!root){
            return;
        }

        curr_sum += root->val;
        curr_path.push_back(root->val);

        if (!root->left && !root->right) {
            // LEAF
            if (curr_sum == targetSum) {
                ans.push_back(curr_path);
            }
        }

        get_target_path(root->left, targetSum, curr_sum, curr_path, ans);
        get_target_path(root->right, targetSum, curr_sum, curr_path, ans);
        curr_sum -= root->val;
        curr_path.pop_back();
    }
};