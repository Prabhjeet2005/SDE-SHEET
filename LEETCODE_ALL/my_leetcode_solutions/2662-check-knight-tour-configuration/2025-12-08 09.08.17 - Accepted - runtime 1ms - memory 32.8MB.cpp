class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        bool is_possible = false;
        int n = grid.size();
        solve(grid,is_possible,0,0,0,n);
        return is_possible;
    }

    private:
    void solve(vector<vector<int>>&grid,bool &is_possible,int index,int row,int col, int n){
        if(row < 0 || row >= n || col < 0 || col >= n){
            return;
        }
        if(grid[row][col] != index){
            return;
        }
        if(index >= n*n-1){
            is_possible = true;
            return;
        }

        vector<int>move_row = {-2,-2,-1,1,2,2,1,-1};
        vector<int>move_col = {-1,1,2,2,1,-1,-2,-2};

        for(int i=0; i<8; i++){
            solve(grid,is_possible,index+1,row + move_row[i],col + move_col[i],n);
        }
    }
};