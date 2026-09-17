class Solution {
    // colors a component
private:
    bool check(int start, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;

        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {

                // if the adjacent node is yet not coloured
                // you will give the opposite color of the node
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }

                // is the adjacent guy having the same color
                // someone did the color it on other path
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        int v = graph.size();

        vector<int> color(v, -1);

        for (int i = 0; i < v; i++) {

            if (color[i] == -1) {

                if (check(i, graph, color) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};