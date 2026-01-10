/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* getLCA(TreeNode* root, int p,int q){
        if(root == NULL){
            return NULL;
        }
        if(root->val == p || root->val == q){
            return root;
        }
        TreeNode* left = getLCA(root->left,p,q);
        TreeNode* right = getLCA(root->right,p,q);

        if(left != NULL && right != NULL){
            return root;
        }
        else if(left == NULL && right != NULL){
            return right;
        }
        else if(left != NULL && right == NULL){
            return left;
        }
        else{
            return NULL;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans = getLCA(root,p->val,q->val);
        return ans;
    }
};