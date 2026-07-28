class Solution {
public:
    void dfs(int node, int parent, int &timer,
             vector<int> &disc,
             vector<int> &low,
             vector<vector<int>> &result,
             unordered_map<int, list<int>> &adj,
             unordered_map<int, bool> &visited) {

        visited[node] = true;
        disc[node] = low[node] = timer++;

        for (auto neighbour : adj[node]) {

            if (neighbour == parent) {
                continue;
            }

            if (!visited[neighbour]) {

                dfs(neighbour, node, timer, disc, low, result, adj, visited);

                low[node] = min(low[node], low[neighbour]);

                if (low[neighbour] > disc[node]) {
                    result.push_back({node, neighbour});
                }
            }
            else {
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        unordered_map<int, list<int>> adj;

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        unordered_map<int, bool> visited;

        vector<vector<int>> result;
        int timer = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, timer, disc, low, result, adj, visited);
            }
        }

        return result;
    }
};