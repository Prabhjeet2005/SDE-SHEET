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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> output;
        if (root == NULL) {
            return output;
        }
        map<int, map<int, vector<int>>> map;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push(make_pair(root, make_pair(0,0)));

        while (!q.empty()) {

            pair<TreeNode*, pair<int, int>> front = q.front();
            q.pop();

            int hd = front.second.first;
            int lvl = front.second.second;
            TreeNode* curr = front.first;
            map[hd][lvl].push_back(curr->val);

            if (curr->left) {
                q.push(make_pair(curr->left, make_pair(hd - 1, lvl + 1)));
            }
            if (curr->right) {
                q.push(make_pair(curr->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        for (auto i : map) {
                vector<int>ans;
                for(auto j: i.second){
                    sort(j.second.begin(), j.second.end());
                    for(auto k: j.second)
                    ans.push_back(k);
                }
                output.push_back(ans);
        }
        return output;
    }
};