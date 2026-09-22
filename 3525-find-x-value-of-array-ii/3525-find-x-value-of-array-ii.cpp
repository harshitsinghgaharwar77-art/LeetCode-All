class Solution {
private:
    struct Node {
        int prod;
        array<int, 5> cnt;

        Node() {
            prod = 1;
            cnt.fill(0);
        }
    };

    int k;

    Node mergeNode(const Node &a, const Node &b) {
        Node res;

        // Product of the complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside a
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefixes which start in a and continue into b
        for (int r = 0; r < k; r++) {
            int rem = (a.prod * r) % k;
            res.cnt[rem] += b.cnt[r];
        }

        return res;
    }

public:
    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {

        k = K;
        int n = nums.size();

        // Iterative segment tree
        int size = 1;
        while (size < n) {
            size *= 2;
        }

        vector<Node> tree(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            int rem = nums[i] % k;

            tree[size + i].prod = rem;
            tree[size + i].cnt[rem] = 1;
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[2 * i], tree[2 * i + 1]);
        }

        // Point update
        auto update = [&](int index, int value) {
            int pos = size + index;

            tree[pos] = Node();

            int rem = value % k;

            tree[pos].prod = rem;
            tree[pos].cnt[rem] = 1;

            pos /= 2;

            while (pos >= 1) {
                tree[pos] = mergeNode(tree[2 * pos],
                                       tree[2 * pos + 1]);
                pos /= 2;
            }
        };

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            nums[index] = value;
            update(index, value);

            // Query [start, n-1]
            int l = size + start;
            int r = size + n;

            Node leftRes;
            Node rightRes;

            while (l < r) {

                if (l & 1) {
                    leftRes = mergeNode(leftRes, tree[l]);
                    l++;
                }

                if (r & 1) {
                    --r;
                    rightRes = mergeNode(tree[r], rightRes);
                }

                l /= 2;
                r /= 2;
            }

            Node res = mergeNode(leftRes, rightRes);

            answer.push_back(res.cnt[x]);
        }

        return answer;
    }
};