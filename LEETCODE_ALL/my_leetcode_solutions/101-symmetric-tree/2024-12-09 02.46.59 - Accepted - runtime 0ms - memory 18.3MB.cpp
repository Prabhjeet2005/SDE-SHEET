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
    void solve(TreeNode* root1, TreeNode* root2, bool& ans) {
        if (root1 == NULL && root2 == NULL) {
            return;
        } else if ((root1 == NULL || root2 == NULL)) {
            ans = false;
            return;
        }
        solve(root1->left, root2->right, ans);
        if (root1->val != root2->val) {
            ans = false;
        }
        solve(root1->right, root2->left, ans);
    }

public:
    bool isSymmetric(TreeNode* root) {
        bool ans = true;
        if (root == NULL) {
            return ans;
        }
        solve(root->left, root->right, ans);
        return ans;
    }
};