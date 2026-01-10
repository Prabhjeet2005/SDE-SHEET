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
    TreeNode* solve(vector<int> &postorder,vector<int>&inorder, int &postIndex,
    int inorderStart,int inorderEnd, unordered_map<int,int>&findIndex) {
        if (postIndex == -1 || inorderStart > inorderEnd) {
            return NULL;
        }
        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);
        int pos = findIndex[element];

        root->right = solve(postorder,inorder,postIndex,pos+1,inorderEnd,findIndex);
        root->left = solve(postorder,inorder,postIndex,inorderStart,pos-1,findIndex);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        unordered_map<int, int> findIndex;
        for (int i = 0; i < size; i++) {
            findIndex[inorder[i]] = i;
        }
        int postIndex = size - 1;
        TreeNode* ans = solve(postorder,inorder,postIndex,0,size-1,findIndex);
        return ans;
    }
};