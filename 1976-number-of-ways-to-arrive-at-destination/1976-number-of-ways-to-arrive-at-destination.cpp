class Solution {
public:
    typedef pair<long long, int> p;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        // u -> {{v1, t1}, {v2, t2}}
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<p, vector<p>, greater<p>> pq; // min-heap
        
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathCounts(n, 0);

        int M = 1e9 + 7;

        result[0] = 0;
        pathCounts[0] = 1;
        pq.push({0, 0}); // {time, node}

        while(!pq.empty()){
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto &vec : adj[currNode]){
                int nbr = vec.first;
                int roadTime = vec.second;

                if(currTime + roadTime < result[nbr]){
                    result[nbr] = currTime + roadTime;
                    pq.push({result[nbr], nbr});
                    pathCounts[nbr] = pathCounts[currNode];
                }
                else if(currTime + roadTime == result[nbr]){
                    pathCounts[nbr] = 
                        (pathCounts[nbr] + pathCounts[currNode]) % M;
                }
            }
        }

        return pathCounts[n-1];
    }
};