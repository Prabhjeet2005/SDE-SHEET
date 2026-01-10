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
        vector<vector<int>>finalans;
        if(root== NULL){
            return finalans;
        }
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int qsize = q.size();
            vector<int>tempans;
            for(int i=0;i<qsize;i++){
                TreeNode* front = q.front();
                q.pop();

                tempans.push_back(front->val);
                if(front->left != NULL){
                    q.push(front->left); 
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
                finalans.push_back(tempans);
        }
        return finalans;
    }
};