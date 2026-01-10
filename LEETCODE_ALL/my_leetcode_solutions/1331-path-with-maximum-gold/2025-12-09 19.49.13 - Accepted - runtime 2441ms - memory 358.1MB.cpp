class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int row_size = grid.size(),col_size = grid[0].size();
        vector<vector<bool>>visited(row_size,vector<bool>(col_size,false));
        int max_sum = INT_MIN,curr_sum = 0;
        for(int i=0; i<row_size; i++)
            for(int j=0; j<col_size; j++){
                if(grid[i][j]==0)continue;
                solve(grid,visited,i,j,curr_sum,max_sum);
            }

        return max_sum == INT_MIN ? 0 : max_sum;
    }

    private:
    void solve(vector<vector<int>>&grid,vector<vector<bool>>&visited,int row,int col,int  &curr_sum,int &max_sum){

        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return;
        }
        if(visited[row][col] == true || grid[row][col] == 0)return;

        
        // DLRU
        vector<int>move_row = {1,0,0,-1};
        vector<int>move_col = {0,-1,1,0};

        
        for(int i=0; i<4; i++){
            visited[row][col] = true;
            curr_sum += grid[row][col];
            max_sum = max(max_sum,curr_sum);
            solve(grid,visited,row+move_row[i],col + move_col[i],curr_sum,max_sum);
            curr_sum -= grid[row][col];
            visited[row][col] = false;
            
        }
    }
};