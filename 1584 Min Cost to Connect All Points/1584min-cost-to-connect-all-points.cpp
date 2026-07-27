class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> key(n, INT_MAX);
        vector<bool> mst(n, false);
        vector<int> parent(n, -1);

        key[0] = 0;

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int mini = INT_MAX;
            int u = -1;

            // find minimum key vertex
            for(int j = 0; j < n; j++) {
                if(!mst[j] && key[j] < mini) {
                    mini = key[j];
                    u = j;
                }
            }

            mst[u] = true;
            ans += key[u];

            // update adjacent vertices
            for(int v = 0; v < n; v++) {

                if(!mst[v]) {

                    int w = abs(points[u][0] - points[v][0]) +
                            abs(points[u][1] - points[v][1]);

                    if(w < key[v]) {
                        key[v] = w;
                        parent[v] = u;
                    }
                }
            }
        }

        return ans;
    }
};