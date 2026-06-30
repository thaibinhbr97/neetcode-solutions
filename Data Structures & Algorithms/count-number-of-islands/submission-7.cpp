// Time: O(r * c), r: # of rows, c: # of cols
// Spacce: O(r * c)
// class Solution {
//     int dr[4] = {-1, 1, 0, 0};
//     int dc[4] = {0, 0, -1, 1};
// public:
//     bool isValid(int r, int c, int rows, int cols) {
//         if (r < 0 || c < 0 || r >= rows || c >= cols) {
//             return false;
//         }
//         return true;
//     }
//     void bfs(int r, int c, int rows, int cols, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
//         queue<pair<int, int>> q;
//         q.push({r, c});
//         visited[r][c] = true;

//         while (!q.empty()) {
//             pair<int, int> front = q.front(); q.pop();
//             int r = front.first;
//             int c = front.second;
//             for (int i = 0; i < 4; i++) {
//                 int ur = r + dr[i];
//                 int uc = c + dc[i];
//                 if (isValid(ur, uc, rows, cols) && grid[ur][uc] == '1' && !visited[ur][uc]) {
//                     visited[ur][uc] = true;                    
//                     q.push({ur, uc});
//                 }
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty() || grid[0].empty()) return 0;

//         int rows = grid.size();
//         int cols = grid[0].size();
//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//         int islands = 0;
//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (grid[r][c] == '1' && !visited[r][c]) {
//                     bfs(r, c, rows, cols, visited, grid);
//                     islands++;
//                 }
//             }
//         }
//         return islands;
//     }
// };


// Time: O(r * c), r: # of rows, c: # of cols
// Spacce: O(1)
// class Solution {
//     int dr[4] = {-1, 1, 0, 0};
//     int dc[4] = {0, 0, -1, 1};
// public:
//     bool isValid(int r, int c, int rows, int cols) {
//         if (r < 0 || c < 0 || r >= rows || c >= cols) {
//             return false;
//         }
//         return true;
//     }
//     void bfs(int r, int c, int rows, int cols, vector<vector<char>>& grid) {
//         queue<pair<int, int>> q;
//         q.push({r, c});
//         grid[r][c] = '0';

//         while (!q.empty()) {
//             pair<int, int> front = q.front(); q.pop();
//             int r = front.first;
//             int c = front.second;
//             for (int i = 0; i < 4; i++) {
//                 int ur = r + dr[i];
//                 int uc = c + dc[i];
//                 if (isValid(ur, uc, rows, cols) && grid[ur][uc] == '1') {
//                     grid[ur][uc] = '0';                
//                     q.push({ur, uc});
//                 }
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty() || grid[0].empty()) return 0;

//         int rows = grid.size();
//         int cols = grid[0].size();
//         int islands = 0;
//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (grid[r][c] == '1') {
//                     bfs(r, c, rows, cols, grid);
//                     islands++;
//                 }
//             }
//         }
//         return islands;
//     }
// };



// // Time: O(r * c), r: # of rows, c: # of cols
// // Space: O(1) for explicit auxiliary, O(r * c) for implicit recursion stack
// class Solution {
//     int dr[4] = {-1, 1, 0, 0};
//     int dc[4] = {0, 0, -1, 1};
// public:
//     bool isValid(int r, int c, int rows, int cols) {
//         if (r < 0 || c < 0 || r >= rows || c >= cols) {
//             return false;
//         }
//         return true;
//     }
//     void dfs(int r, int c, int rows, int cols, vector<vector<char>>& grid) {
//         if (!isValid(r, c, rows, cols) || grid[r][c] == '0') {
//             return;
//         }
//         grid[r][c] = '0';
//         for (int i = 0; i < 4; i++) {
//             dfs(r + dr[i], c + dc[i], rows, cols, grid);
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty() || grid[0].empty()) return 0;

//         int rows = grid.size();
//         int cols = grid[0].size();
//         int islands = 0;
//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (grid[r][c] == '1') {
//                     dfs(r, c, rows, cols, grid);
//                     islands++;
//                 }
//             }
//         }
//         return islands;
//     }
// };



// Time: O(r * c), r: # of rows, c: # of cols
// Space: O(r * c)
class Solution {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
public:
    bool isValid(int r, int c, int rows, int cols) {
        return (r >= 0 && c >= 0 && r < rows && c < cols);
    }
    void dfs(int r, int c, int rows, int cols, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (!isValid(r, c, rows, cols) || grid[r][c] == '0' || visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i], rows, cols, grid, visited);
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
                    dfs(r, c, rows, cols, grid, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};


