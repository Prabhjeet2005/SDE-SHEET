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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(root->val == key){
            return delete_from_BST(root,key);
        }
        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }

        return root;
    }

    private:
    TreeNode* delete_from_BST(TreeNode*& root,int key){
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        if(!root->left || !root->right){
            // 1 Child
            if(!root->left){
                TreeNode* remaining_tree = root->right;
                delete root;
                return remaining_tree;
            }
            else{
                TreeNode* remaining_tree = root->left;
                delete root;
                return remaining_tree;
            }
        }
        else{
            // 2 Children
            TreeNode* inorder_successor = get_inorder_successor(root->right);
            root->val = inorder_successor->val;
            root->right = deleteNode(root->right,inorder_successor->val);
            return root;
        }
    }

    TreeNode* get_inorder_successor(TreeNode* &root){
        if(!root)return nullptr;
        if(!root->left)return root;
        return get_inorder_successor(root->left);
    }
};