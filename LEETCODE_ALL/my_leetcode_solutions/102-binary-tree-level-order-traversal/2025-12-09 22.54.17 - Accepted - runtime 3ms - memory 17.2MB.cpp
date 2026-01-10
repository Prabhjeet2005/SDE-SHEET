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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            vector<int>curr;
            for(int i=0; i<size; i++){
                TreeNode* front_node = queue.front();queue.pop();
                curr.push_back(front_node->val);
                if(front_node->left)queue.push(front_node->left);
                if(front_node->right)queue.push(front_node->right);
            }
            ans.push_back(curr);
        }

        return ans;

    }
};