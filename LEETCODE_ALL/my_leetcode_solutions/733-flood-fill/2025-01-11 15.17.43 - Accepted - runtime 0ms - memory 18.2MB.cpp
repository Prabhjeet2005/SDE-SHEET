class Solution {
    void dfs(vector<vector<int>>& ans, int sr, int sc, vector<int>& directionx,
             vector<int>& directiony, int color, int initialColor) 
             {
                ans[sr][sc] = color;
                int n = ans.size();
                int m = ans[0].size();

                for(int i=0; i<4; i++){
                    int nrow = sr + directionx[i];
                    int ncol = sc + directiony[i];

                    if(nrow>=0 && nrow < n && ncol>=0 && ncol<m
                    && ans[nrow][ncol]==initialColor && ans[nrow][ncol]!=color){
                        dfs(ans, nrow, ncol, directionx, directiony, color, initialColor);
                    }
                }
             }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int initialColor = ans[sr][sc];

        vector<int> directionx = {0, -1, 0, 1}; // LURD
        vector<int> directiony = {-1, 0, 1, 0}; // LURD

        dfs(ans, sr, sc, directionx, directiony, color, initialColor);

        return ans;
    }
};