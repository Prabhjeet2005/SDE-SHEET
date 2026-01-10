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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_index;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_index[inorder[i]] = i;
        }
        TreeNode* root =
            create_tree(preorder, inorder, inorder_index, 0,
                        preorder.size() - 1, 0, inorder.size() - 1);

        return root;
    }

private:
    TreeNode* create_tree(vector<int>& preorder, vector<int>& inorder,
                          unordered_map<int, int>& inorder_index, int pre_start,
                          int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }
        TreeNode* root_node = new TreeNode(preorder[pre_start]);
        int root_inorder_index = inorder_index[preorder[pre_start]];

        int left_inorder_start = in_start;             //
        int left_inorder_end = root_inorder_index - 1; //
        int left_inorder_size = left_inorder_end - left_inorder_start + 1;
        int left_preorder_start = pre_start + 1; //
        int left_preorder_end = left_preorder_start + left_inorder_size - 1;

        int right_inorder_start = root_inorder_index + 1; //
        int right_inorder_end = in_end;                   //
        int right_preorder_start = left_preorder_end + 1;
        int right_preorder_end = pre_end;

        root_node->left = create_tree(preorder, inorder, inorder_index,
                                      left_preorder_start, left_preorder_end,
                                      left_inorder_start, left_inorder_end);

        root_node->right = create_tree(preorder, inorder, inorder_index,
                                       right_preorder_start, right_preorder_end,
                                       right_inorder_start, right_inorder_end);
        return root_node;
    }
};