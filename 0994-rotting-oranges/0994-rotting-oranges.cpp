class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j <n ; j++){
                if(grid[i][j] == 2){
                    // rotten orranges
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        // all oranges are already rotten
        if(cnt == 0) return 0;
        int mints = 0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                for(auto dir:directions){
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];
                    if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == 1){
                        grid[x_][y_] = 2;
                        q.push({x_,y_});
                        cnt--;
                    }
                }
            }
            mints++;
        }
        return cnt == 0 ? mints-1 : -1;
    }
};