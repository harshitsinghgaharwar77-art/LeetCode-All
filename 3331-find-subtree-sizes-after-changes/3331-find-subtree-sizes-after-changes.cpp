
class Solution {
public:
    vector<vector<int>> adj, newAdj;
    vector<int> ans;
    int last[26];

    void dfs1(int u, vector<int>& parent, string& s) {
        int c = s[u] - 'a';

        int old = last[c];

        // Determine the new parent
        int p = (old == -1 ? parent[u] : old);

        if (u != 0) {
            newAdj[p].push_back(u);
        }

        // Update nearest ancestor
        last[c] = u;

        for (int v : adj[u]) {
            dfs1(v, parent, s);
        }

        // Backtracking
        last[c] = old;
    }

    int dfs2(int u) {
        int sz = 1;

        for (int v : newAdj[u]) {
            sz += dfs2(v);
        }

        return ans[u] = sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        newAdj.resize(n);
        ans.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        fill(last, last + 26, -1);

        dfs1(0, parent, s);

        dfs2(0);

        return ans;
    }
};
