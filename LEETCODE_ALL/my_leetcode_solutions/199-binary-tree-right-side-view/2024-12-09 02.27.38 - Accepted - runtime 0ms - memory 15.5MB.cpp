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
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mapping;
        vector<int> ans;

        if (root == NULL) {
            return ans;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int lvl = front.second;
            TreeNode* temp = front.first;

            mapping[lvl] = temp->val;

            if (temp->left) {
                q.push({temp->left, lvl + 1});
            }
            if (temp->right) {
                q.push({temp->right, lvl + 1});
            }
        }

        for(auto i:mapping){
            ans.push_back(i.second);
        }
        return ans;
    }
};