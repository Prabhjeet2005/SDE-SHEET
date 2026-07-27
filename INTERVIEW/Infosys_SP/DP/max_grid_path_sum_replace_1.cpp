#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<vector<long long>>>dp;
public:
    long long maxPathSum(vector<vector<int>>& grid) {
        long long ans = 0;
        dp.resize(grid.size()+1,vector<vector<long long>>(grid[0].size()+1,vector<long long>(2,-1e9)));
        // 
        ans = get_max_path_sum(grid,0,0,1);
        return ans;
    }

    long long get_max_path_sum(vector<vector<int>>&grid,int row,int col,int replacement_left){

        int n = grid.size(),m=grid[0].size();
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ){
            return -1e9;
        }

        if(row == grid.size()-1 && col == grid[0].size()-1){
            return max(grid[n-1][m-1],-grid[n-1][m-1]);
        }

        if(dp[row][col][replacement_left]!=-1e9)return dp[row][col][replacement_left];

        // DR
        vector<int>dc = {0,1};
        vector<int>dr = {1,0};
        long long max_ans = -1e9;

        for(int i=0; i<2; i++){
            long long curr = -1e9;
            long long not_replace_down = get_max_path_sum(grid,row+dr[i],col+dc[i],replacement_left);
            long long replace_down = -1e9;
            if(replacement_left != 0){
                replace_down = get_max_path_sum(grid,row + dr[i],col + dc[i],0);
            }
            curr = max(not_replace_down,replace_down);
            max_ans = max(max_ans,curr);
        }
        long long curr_val = replacement_left == 0 ? grid[row][col]:-grid[row][col];
        return dp[row][col][replacement_left]=grid[row][col]+max_ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: 
    // Optimal Path: 1 -> -5 (flip to 5) -> 3. 
    // Expected Sum = 1 + 5 + 3 = 9.
    vector<vector<int>> grid1 = {
        {1, -5},
        {-2, 3}
    };
    
    // Test Case 2:
    // Optimal Path: 2 -> -1 -> -3 (flip to 3) -> 4. 
    // Expected Sum = 2 - 1 + 3 + 4 = 8.
    vector<vector<int>> grid2 = {
        {2, -1, 1},
        {-5, -3, 4},  
        {1, -2, 2}
    };

    cout << "Test Case 1 Result: " << sol.maxPathSum(grid1) << " (Expected: 9)" << endl;
    cout << "Test Case 2 Result: " << sol.maxPathSum(grid2) << " (Expected: 8)" << endl;
    
    return 0;
}