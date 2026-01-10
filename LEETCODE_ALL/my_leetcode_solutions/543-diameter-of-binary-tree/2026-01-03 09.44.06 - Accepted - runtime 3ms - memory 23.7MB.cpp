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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int max_diameter = 0;
        get_max_diameter(root,max_diameter);
        return max_diameter;
    }
    private:
    int get_max_diameter(TreeNode* root,int &max_diameter){
        if(!root)return 0;
        int left_height = get_max_diameter(root->left,max_diameter);
        int right_height = get_max_diameter(root->right,max_diameter);
        max_diameter = max(max_diameter,left_height + right_height);
        return 1+max(left_height,right_height);
    }
};