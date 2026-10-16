
class Solution {
    static const int MOD = 1000000007;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0) return;

        long long x = seg[node].lazy;
        int mid = (l + r) / 2;

        for (int child : {node * 2, node * 2 + 1}) {
            int len = (child == node * 2)
                          ? mid - l + 1
                          : r - mid;

            seg[child].sq =
                (seg[child].sq + 2LL * x * seg[child].sum
                 + x * x % MOD * len) % MOD;

            seg[child].sum =
                (seg[child].sum + x * len) % MOD;

            seg[child].lazy = (seg[child].lazy + x) % MOD;
        }

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            long long x = 1;
            int len = r - l + 1;

            seg[node].sq =
                (seg[node].sq + 2LL * seg[node].sum
                 + len) % MOD;

            seg[node].sum = (seg[node].sum + len) % MOD;
            seg[node].lazy = (seg[node].lazy + x) % MOD;
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, last[nums[i]] + 1, i);

            last[nums[i]] = i;
            ans = (ans + seg[1].sq) % MOD;
        }

        return (int)ans;
    }
};
