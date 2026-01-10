
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
    int find(vector<int> inorder,int s,int e,int element, int n){
        for(int i=s; i<=e; i++){
            if(inorder[i]==element){
                return i;
            }
        }
            return -1;
    }
    TreeNode* solve(vector<int> preorder, vector<int> inorder,
                    int& indexPreorder, int inorderStart,int    inorderEnd, int size) 
{
    if (indexPreorder == size || inorderEnd < inorderStart) {
            return NULL;
    }

    int element = preorder[indexPreorder++];
    TreeNode* root = new TreeNode(element);
    int pos = find(inorder,inorderStart,inorderEnd,element,size);

    root->left = solve(preorder, inorder, indexPreorder, inorderStart, pos - 1, size);
        root->right = solve(preorder, inorder, indexPreorder, pos+1, inorderEnd,  size);
        return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();
        
        int index = 0;
        TreeNode* ans = solve(preorder, inorder, index, 0, n - 1 ,n);
        return ans;
    }
};