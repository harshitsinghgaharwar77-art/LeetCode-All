class Solution {
    private:
    void dfs(int node, vector<int> adjLs[], vector<bool> &vis){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> adjLs[v];

        // to change adjacency matrix to list 
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                }
            }
        }

        vector<bool> vis(v, 0);;
        int cnt = 0;

        for(int i = 0; i < v; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjLs, vis);
            }
        }

        return cnt;
    }
};