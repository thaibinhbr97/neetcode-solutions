class Solution {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
public:
    bool isValid(int r, int c, int rows, int cols) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return false;
        }
        return true;
    }
    void bfs(int r, int c, int rows, int cols, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;

        while (!q.empty()) {
            pair<int, int> front = q.front(); q.pop();
            int r = front.first;
            int c = front.second;
            for (int i = 0; i < 4; i++) {
                int ur = r + dr[i];
                int uc = c + dc[i];
                if (isValid(ur, uc, rows, cols) && grid[ur][uc] == '1' && !visited[ur][uc]) {
                    visited[ur][uc] = true;                    
                    q.push({ur, uc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islands = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' && !visited[r][c]) {
                    bfs(r, c, rows, cols, visited, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};
