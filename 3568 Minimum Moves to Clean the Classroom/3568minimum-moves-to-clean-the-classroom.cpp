class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        vector<pair<int, int>> litter;
        int sx, sy;

        // Find starting position and all litter cells
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(classroom[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                else if(classroom[i][j] == 'L'){
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // No litter to clean
        if(k == 0) return 0;

        int fullMask = (1 << k) - 1;

        // best[i][j][mask] = maximum energy with which
        // we have reached (i,j) after collecting mask
        vector<vector<vector<int>>> best(
            n, vector<vector<int>>(m, vector<int>(1 << k, -1))
        );

        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, 0, energy});
        best[sx][sy][0] = energy;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int moves = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [x, y, mask, currEnergy] = q.front();
                q.pop();

                if(mask == fullMask){
                    return moves;
                }

                for(int d = 0; d < 4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if(classroom[nx][ny] == 'X')
                        continue;

                    if(currEnergy == 0)
                        continue;

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Collect litter
                    if(classroom[nx][ny] == 'L'){
                        for(int i = 0; i < k; i++){
                            if(litter[i].first == nx && litter[i].second == ny){
                                newMask |= (1 << i);
                                break;
                            }
                        }
                    }

                    // Restore energy at recharge station
                    if(classroom[nx][ny] == 'R'){
                        newEnergy = energy;
                    }

                    // If we already reached this state with
                    // more or equal energy, this state is useless
                    if(best[nx][ny][newMask] >= newEnergy)
                        continue;

                    best[nx][ny][newMask] = newEnergy;

                    q.push({nx, ny, newMask, newEnergy});
                }
            }

            moves++;
        }

        return -1;
    }
};