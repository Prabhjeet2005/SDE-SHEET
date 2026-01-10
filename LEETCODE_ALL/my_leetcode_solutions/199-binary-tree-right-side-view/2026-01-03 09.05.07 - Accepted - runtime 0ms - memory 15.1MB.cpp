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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        ans = get_right_view(root);
        return ans;
    }
    private:
    vector<int>get_right_view(TreeNode* &root){
        if(!root)return {};
        vector<int>ans;
        queue<TreeNode*>level_queue;
        level_queue.push(root);

        while(!level_queue.empty()){
            int level_queue_size = level_queue.size();
            int right_most_element = INT_MIN;
            for(int i=0; i<level_queue_size; i++){
                TreeNode* front = level_queue.front();
                level_queue.pop();
                if(front->left)level_queue.push(front->left);
                if(front->right)level_queue.push(front->right);
                right_most_element = front->val;
            }
            ans.push_back(right_most_element);
        }
        return ans;
    }
};