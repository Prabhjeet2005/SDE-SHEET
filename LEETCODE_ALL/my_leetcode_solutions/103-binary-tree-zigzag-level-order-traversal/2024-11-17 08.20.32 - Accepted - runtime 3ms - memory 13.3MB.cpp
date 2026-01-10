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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>finalans;
        queue<TreeNode* > q;
        if(root==NULL){
            return finalans;
        }
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int size=q.size();
            int index=0;
            vector<int>ans(size);

            for(int i=0; i<size; i++){
                TreeNode* temp=q.front();
                q.pop();

                if(leftToRight){
                    index = i;
                }else{
                    index = size-i-1;
                }
                ans[index]=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            leftToRight=!leftToRight;
            finalans.push_back(ans);
        }
        return finalans;
    }
};