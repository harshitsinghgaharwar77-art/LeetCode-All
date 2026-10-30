#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Build the adjacency list graph
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // dist[u][c] stores the min distance to reach node 'u' with 'c' consecutive identical characters
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));
        dist[0][1] = 0;

        // Min-heap priority queue storing tuples of {distance, current_node, consecutive_count}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, c] = pq.top();
            pq.pop();

            // Skip if we've already found a strictly shorter path to this exact state
            if (d > dist[u][c]) {
                continue;
            }

            // Since it's a min-heap, the first time we pop the destination node, 
            // it is guaranteed to be the shortest path
            if (u == n - 1) {
                return d;
            }

            // Explore neighbors
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                if (labels[u] == labels[v]) {
                    // Character continues, increment consecutive count
                    if (c + 1 <= k && d + w < dist[v][c + 1]) {
                        dist[v][c + 1] = d + w;
                        pq.push({d + w, v, c + 1});
                    }
                } else {
                    // Character changes, reset consecutive count back to 1
                    if (d + w < dist[v][1]) {
                        dist[v][1] = d + w;
                        pq.push({d + w, v, 1});
                    }
                }
            }
        }

        // If the queue is exhausted and we never reached n - 1
        return -1;
    }
};