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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>path_sum_count_map;
        long long path_sum=0;
        int count_path = 0;
        path_sum_count_map[0]++;
        get_count_path(root,targetSum,path_sum,count_path,path_sum_count_map);
        return count_path;

    }

    private:
    int get_count_path(TreeNode*& root,int targetSum,long long path_sum, int &count_path,unordered_map<long long,int>&path_sum_count_map){
        if(!root){
            return 0;
        }
        path_sum += root->val;
        
        if(path_sum_count_map[ path_sum - targetSum]){
            count_path += path_sum_count_map[ path_sum - targetSum ];
        }

        path_sum_count_map[path_sum]++;
        get_count_path(root->left,targetSum,path_sum,count_path,path_sum_count_map);
        get_count_path(root->right,targetSum,path_sum,count_path,path_sum_count_map);
        path_sum_count_map[path_sum]--;
        return count_path;
    }
};