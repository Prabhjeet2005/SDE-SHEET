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
    pair<int,int> solve(TreeNode* root){
        if(root == NULL){
            return make_pair(0,0);
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

        pair<int,int>ans;
        int currDiameter = left.first + right.first + 1;
        ans.first = max(left.first, right.first) + 1;
        ans.second = max(left.second, max(right.second, currDiameter));
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).second-1;
    }
};