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
    int goodNodes(TreeNode* root) {
        int count_good_nodes = 0,max_till_now = INT_MIN;
        get_count_good_nodes(root,count_good_nodes,max_till_now);
        return count_good_nodes;
    }

    private:
    int get_count_good_nodes(TreeNode*& root,int &count_good_nodes,int max_till_now){
        if(!root)return 0;
        if(root->val >= max_till_now)count_good_nodes++;
        max_till_now = max(max_till_now,root->val);
        int left_count = get_count_good_nodes(root->left,count_good_nodes,max_till_now);
        int right_count = get_count_good_nodes(root->right,count_good_nodes,max_till_now);
  
        return left_count + right_count;
    }
};