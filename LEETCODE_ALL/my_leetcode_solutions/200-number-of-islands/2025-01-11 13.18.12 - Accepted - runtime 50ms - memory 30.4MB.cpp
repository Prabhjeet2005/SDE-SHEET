class Solution {
    void bfs(int row, int col, vector<vector<bool>>& visited,
             vector<vector<char>>& grid, int n, int m) {
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int qrow = front.first;
            int qcol = front.second;
            vector<int> directionRow = {0, -1, 0, 1}; // LURD
            vector<int> directionCol = {-1, 0, 1, 0};

            for (int i = 0; i < 4; i++) {
                int nrow = qrow + directionRow[i];
                int ncol = qcol + directionCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] == false && grid[nrow][ncol] == '1') {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, visited, grid, n, m);
                }
            }
        }
        return cnt;
    }
};