class Solution {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
public:
    bool isValid(int r, int c, int rows, int cols) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }
    int bfs(int r, int c, int rows, int cols, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        int area = 1;
        while (!q.empty()) {
            pair<int, int> front = q.front(); q.pop();
            int r = front.first;
            int c = front.second;
            for (int i = 0; i < 4; i++) {
                int ur = r + dr[i];
                int uc = c + dc[i];
                if (isValid(ur, uc, rows, cols) && grid[ur][uc] == 1 && !visited[ur][uc]) {
                    visited[ur][uc] = true;
                    area++;
                    q.push({ur, uc});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    maxArea = max(maxArea, bfs(r, c, rows, cols, grid, visited));
                }
            }
        }
        return maxArea;
    }
};
