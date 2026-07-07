class Solution {
private:
int INF = 2147483647;
vector<int> dr = {-1, 0, 0 ,1};
vector<int> dc = {0, -1, 1, 0};
public:
    bool isValid(vector<vector<int>>& grid, int rows, int cols, int r, int c) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // bfs
        // time: O(m * n)
        // space: O(m * n)
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r,c});
                }
            }
        }
        while (!q.empty()) {
            pair<int,int> front = q.front();
            int r = front.first;
            int c = front.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ur = r + dr[i];
                int uc = c + dc[i];
                if (isValid(grid, rows, cols, ur, uc)) {
                    if (grid[ur][uc] == INF) {
                        grid[ur][uc] = grid[r][c] + 1;
                        q.push({ur,uc});
                    }
                }
            }
        }
    }
};
// [3,-1,0,2],
// [2,3,1,-1],
// [1,-1,5,-1],
// [0,-1,6,7]
// q = [0,2]
// distance = 0
// [
//   [3,-1,0,2],
//   [2,3,1,-1],
//   [1,-1,5,-1],
//   [0,-1,6,7]
// ]