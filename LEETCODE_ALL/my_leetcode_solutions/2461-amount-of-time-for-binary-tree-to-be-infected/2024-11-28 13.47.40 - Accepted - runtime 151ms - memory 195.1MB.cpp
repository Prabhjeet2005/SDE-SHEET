/**
 * Definition for a binary tree TreeNode.
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
    TreeNode* getTargetParent(TreeNode* root, int start,
                              unordered_map<TreeNode*, TreeNode*>& nodeParent) {
        if (root == NULL) {
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = NULL;

        nodeParent[root] = NULL;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->val == start) {
                res = front;
            }

            if (front->left) {
                nodeParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                nodeParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    int infectTree(TreeNode* root,
                   unordered_map<TreeNode*, TreeNode*>& nodeParent) {
        if (root == NULL) {
            return 0;
        }
        int time = 0;
        unordered_map<TreeNode*, bool> visited;
        visited[root] = true;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            bool flag = 0;

            for(int i=0; i<size; i++){
            TreeNode* front = q.front();
            q.pop();
            if (front->left && !visited[front->left]) {
                q.push(front->left);
                visited[front->left] = true;
                flag = 1;
            }
            if (front->right && !visited[front->right]) {
                q.push(front->right);
                visited[front->right] = true;
                flag = 1;
            }
            if (nodeParent[front] && !visited[nodeParent[front]]) {
                flag = 1;
                q.push(nodeParent[front]);
                visited[nodeParent[front]] = true;
            }
        }
            if (flag) {
                time++;
            }
        }

        return time;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> nodeParent;
        TreeNode* targetNode = getTargetParent(root, start, nodeParent);

        return infectTree(targetNode, nodeParent);
    }
};