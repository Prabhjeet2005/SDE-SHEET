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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int mid = start + (end - start)/2;
        TreeNode* root = get_BST(nums,start,end);
        return root;
    }

    private:
    TreeNode* get_BST(vector<int>&nums,int start,int end){
        if(start > end)return nullptr;

        int mid = start + (end - start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = get_BST(nums,start,mid-1);
        root->right = get_BST(nums,mid+1,end);

        return root;
    }
};