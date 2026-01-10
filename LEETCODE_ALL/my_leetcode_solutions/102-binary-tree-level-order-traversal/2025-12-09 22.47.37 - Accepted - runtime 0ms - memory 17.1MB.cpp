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
        vector<int>curr;
        queue<TreeNode*>queue;
        queue.push(root);
        queue.push(nullptr);

        while(!queue.empty()){
            TreeNode* front_node = queue.front();
            queue.pop();

            if(front_node == nullptr){
                if(!queue.empty()){
                    queue.push(nullptr);
                }
                ans.push_back(curr);
                curr.clear();
            }else{
                curr.push_back(front_node->val);
                if(front_node->left){
                    queue.push(front_node->left);
                }
                if(front_node->right){
                    queue.push(front_node->right);
                }
            }
        }

        return ans;

    }
};