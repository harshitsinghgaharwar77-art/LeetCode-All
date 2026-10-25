
class Solution {
private:
    int rows, cols;

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= rows || j >= cols ||
            grid[i][j] == 1) {
            return;
        }

        grid[i][j] = 1; // Mark visited

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        // Step 1: Remove islands connected to the boundary
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0)
                dfs(grid, i, 0);
            if (grid[i][cols - 1] == 0)
                dfs(grid, i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            if (grid[0][j] == 0)
                dfs(grid, 0, j);
            if (grid[rows - 1][j] == 0)
                dfs(grid, rows - 1, j);
        }
        // Step 2: Count remaining closed islands
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
