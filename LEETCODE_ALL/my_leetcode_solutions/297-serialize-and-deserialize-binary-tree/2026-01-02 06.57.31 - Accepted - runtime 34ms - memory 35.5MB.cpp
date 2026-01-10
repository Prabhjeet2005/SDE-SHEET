/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoded_str = "";
        // PREORDER BECAUSE NATURAL FLOW
        calculate_preorder(root,encoded_str);
        return encoded_str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int curr = 0;
        TreeNode* root = build_tree(data,curr);
        return root;
    }

private:

    TreeNode* build_tree(string &data,int &curr_index){
        if(curr_index >= data.size())return nullptr;

        int next_space = data.find(' ',curr_index);
        string curr_node = data.substr(curr_index,next_space-curr_index);
        curr_index = next_space+1;

        if(curr_node == "N"){
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(curr_node));
        node->left = build_tree(data,curr_index);
        node->right = build_tree(data,curr_index);
        return node;
    }


    void calculate_preorder(TreeNode* root,string &encoded_str){
        if(!root){
            encoded_str += "N ";
            return;
        } 
        encoded_str += to_string(root->val) + " ";
        calculate_preorder(root->left,encoded_str);
        calculate_preorder(root->right,encoded_str);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));