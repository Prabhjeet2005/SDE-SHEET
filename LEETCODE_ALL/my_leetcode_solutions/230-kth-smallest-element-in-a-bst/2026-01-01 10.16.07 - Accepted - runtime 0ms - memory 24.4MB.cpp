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
    int kthSmallest(TreeNode* root, int k) {
        int current_count = 0;
        int ans = -1;
        inorder_calculate_k(root, k, current_count,ans);
        return ans;
    }

private:
    void inorder_calculate_k(TreeNode*& root, int k, int& current_count,int &ans) {
        if (!root)
            return;
        inorder_calculate_k(root->left, k, current_count,ans);
        current_count++;
        if (current_count == k) {
            ans = root->val;
            return;
        }
        inorder_calculate_k(root->right, k, current_count,ans);
    }
};