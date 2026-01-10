/**
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* getParentTarget(TreeNode* root, int target,
                              unordered_map<TreeNode*, TreeNode*>& nodeParent) {
        if (root == NULL) {
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);

        nodeParent[root] = NULL;

        TreeNode* targetNode = NULL;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->left) {
                nodeParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                nodeParent[front->right] = front;
                q.push(front->right);
            }
            if (front->val == target) {
                 targetNode = front;
            }
        }
        return targetNode;
    }

    void solve(TreeNode* targetNode,
               unordered_map<TreeNode*, TreeNode*>& nodeParent, int k,
               vector<int>& ans) {
        if (targetNode == NULL) {
            return;
        }
        if(k==0){
            ans.push_back(targetNode->val);return;
        }
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(targetNode);
        visited[targetNode] = true;
        int flag = 0;

        int cnt = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    q.push(front->left);
                    visited[front->left] = true;
                    if (cnt == k) {
                        ans.push_back(front->left->val);
                    }
                }
                if (front->right && !visited[front->right]) {
                    q.push(front->right);
                    visited[front->right] = true;
                    if (cnt == k) {
                        ans.push_back(front->right->val);
                    }
                }
                if (nodeParent[front] && !visited[nodeParent[front]]) {
                    q.push(nodeParent[front]);
                    visited[nodeParent[front]] = true;
                    if (cnt == k) {
                        TreeNode* temp = nodeParent[front];
                        ans.push_back(nodeParent[front]->val);
                    }
                }
            }
            cnt++;
            }
        
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> nodeParent;
        TreeNode* targetNode = getParentTarget(root, target->val, nodeParent);
        vector<int> ans;
        solve(targetNode, nodeParent, k, ans);
        return ans;
    }
};