
class Solution {
public:
    int m, n, ans, nonObstacles;
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,-1}, {0,1}};

    void solve(vector<vector<int>>& grid, int cnt, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1){
            return;
        }

        if(grid[i][j] == 2){
            if(cnt == nonObstacles){
                ans++;
            }
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;

        for(vector<int> &dir: directions){
            int newI = i + dir[0];
            int newJ = j + dir[1];

            solve(grid, cnt + 1, newI, newJ);
        }

        grid[i][j] = temp; // backtrack
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        ans = 0, nonObstacles = 0;

        int startX = 0, startY = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    nonObstacles++;
                }

                if(grid[i][j] == 1){
                    startX = i;
                    startY = j;
                }
            }
        }

        nonObstacles += 2; // empty cells + start + end

        solve(grid, 1, startX, startY);

        return ans;
    }
};
