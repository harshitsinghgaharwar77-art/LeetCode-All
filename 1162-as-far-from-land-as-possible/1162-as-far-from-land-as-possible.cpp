
class Solution {
public:
    vector<vector<int>> distance = {{0,1},{0,-1},{1,0},{-1,0}};

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;

        // mai land se sea pe jaane ka try karunga
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // push the land
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        // no land cell or no water cell
        if(q.empty() || q.size() == n*m) return -1;

        int dist = 0;

        while(!q.empty()){
            int N = q.size();

            while(N--){
                auto frontNode = q.front();
                q.pop();

                int x = frontNode.first;
                int y = frontNode.second;

                for(auto dir: distance){
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(x_ >= 0 && x_ < n &&
                       y_ >= 0 && y_ < m &&
                       grid[x_][y_] == 0 &&
                       vis[x_][y_] == 0){

                        vis[x_][y_] = 1;
                        q.push({x_,y_});
                    }
                }
            }

            dist++;
        }

        return dist - 1;
    }
};
