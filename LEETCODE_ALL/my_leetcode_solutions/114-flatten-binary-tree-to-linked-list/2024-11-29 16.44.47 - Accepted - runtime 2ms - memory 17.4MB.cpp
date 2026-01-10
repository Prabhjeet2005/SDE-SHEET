/**
 * Definition for a binary tree TreeNode.
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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left == NULL){
                cout<<curr->val<<" ";
                curr=curr->right;
            }
            else
            {
                TreeNode* pred = curr->left;
                while(pred->right != NULL && pred->right != curr->right){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = curr->right;
                    curr->right = curr->left;
                }
                cout<<curr->val<<" ";
                curr->left = NULL;
                curr = curr->right;
            }
        }
    }
};