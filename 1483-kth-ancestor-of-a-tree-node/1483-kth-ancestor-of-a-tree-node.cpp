
class TreeAncestor {
public:
    vector<vector<int>> ancestorTable;
    int row;
    int col;
    TreeAncestor(int n, vector<int>& parent) {
        row = n;
        col = log2(n) + 1;
        ancestorTable.resize(row, vector<int>(col, -1));
        // Fill the 0th column first - immediate parent
        for (int i = 0; i < n; i++) {
            ancestorTable[i][0] = parent[i];
        }
        // Build the binary lifting table
        for (int j = 1; j < col; j++) {
            for (int i = 0; i < n; i++) {
                int mid = ancestorTable[i][j - 1];
                if (mid != -1) {
                    ancestorTable[i][j] =
                        ancestorTable[mid][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < col; j++) {
            if (k & (1 << j)) {
                // jth bit is set, so take a 2^j jump
                node = ancestorTable[node][j];
                if (node == -1) return -1;
            }
        }

        return node;
    }
};
