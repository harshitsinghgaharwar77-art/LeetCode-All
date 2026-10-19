class Solution {
public:
    vector<vector<int>> directions = {{1,1}, {0,1}, {1,0}, {-1,0}, {0,-1}, {-1,-1}, {1,-1}, {-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // bfs will work as all the edges have same weight
        int n = grid.size(), m = grid[0].size();
        if(n == 0 || m == 0 || grid[0][0] == 1) return -1;
        auto isSafe = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int lvl = 0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto frontNode = q.front();
                q.pop();
                int x = frontNode.first;
                int y = frontNode.second;
                if(x == n-1 && y == m-1) return lvl+1;
                for(auto dir : directions){
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];
                    if(isSafe(x_,y_) && grid[x_][y_] == 0){
                        q.push({x_,y_});
                        grid[x_][y_] = 1;   // mark visisted
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};