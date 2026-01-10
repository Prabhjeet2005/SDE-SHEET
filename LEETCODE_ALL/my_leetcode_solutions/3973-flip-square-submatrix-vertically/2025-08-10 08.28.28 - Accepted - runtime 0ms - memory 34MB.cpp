class Solution {
    void swapfn(vector<vector<int>>&grid,int col,int start,int end){
        swap(grid[start][col],grid[end][col]);
    }
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        if(k==0){
            return grid;
        }
        for(int i=y; i<y+k; i++){
            int start = x;
            int end = x+k-1;
            while(start < end){
                swapfn(grid,i,start,end);
                start++;end--;
            }
        }
        return grid;
    }
};