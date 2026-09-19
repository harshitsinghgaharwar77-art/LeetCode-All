// snippete for disjoint set
class DisjointSet{
    public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
    private:
    bool isValid(int newr, int newc, int n){
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // step-1 craete the components
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;

                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};

                for(int idx = 0; idx < 4; idx++){
                    int newr = row + dr[idx];
                    int newc = col + dc[idx];

                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int nodeNo = row * n + col;
                        int adjNode = newr * n + newc;

                        ds.unionBySize(nodeNo, adjNode);
                    }
                }
            }
        }

        // step-2
        int mx = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;

                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};

                set<int> components;

                for(int idx = 0; idx < 4; idx++){
                    int newr = row + dr[idx];
                    int newc = col + dc[idx];

                    if(isValid(newr, newc, n)){
                        if(grid[newr][newc] == 1){
                            components.insert(
                                ds.findUPar(newr * n + newc)
                            );
                        }
                    }
                }

                int sizeTotal = 0;

                for(auto i : components)
                    sizeTotal += ds.size[i];

                mx = max(mx, sizeTotal + 1);
            }
        }

        for(int cellNo = 0; cellNo < n * n; cellNo++){
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }

        return mx;
    }
};