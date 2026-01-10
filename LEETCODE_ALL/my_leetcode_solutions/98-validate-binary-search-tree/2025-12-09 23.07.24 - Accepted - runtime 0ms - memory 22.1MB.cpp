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
    bool isValidBST(TreeNode* root) {
        vector<int>inorder;
        calculate_inorder(root,inorder);
        return check_sorted(inorder);
    }
    private:
    void calculate_inorder(TreeNode*& root,vector<int>&inorder){
        if(!root)return;
        calculate_inorder(root->left,inorder);
        inorder.push_back(root->val);
        calculate_inorder(root->right,inorder);
    }
    bool check_sorted(vector<int>&arr){
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1] >= arr[i])return false;
        }
        return true;
    }
};