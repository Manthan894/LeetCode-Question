class Solution {
    static const int MOD = 1'000'000'007;
    class SegmentTree {
        int n;
        vector<long long> sum, sumSq, lazy;
        void apply(int node, int l, int r, long long k) {
            long long len = r - l + 1;
            sumSq[node] = (
                sumSq[node] + 2 * k * sum[node]
                + k * k % MOD * len
            ) % MOD;
            sum[node] = (sum[node] + k * len) % MOD;
            lazy[node] += k;
        }
        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r){
                return;
            }
            int mid = l + (r - l) / 2;
            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
        void update(int node, int l, int r,
                    int ql, int qr) {
            if (qr < l || r < ql)
                return;
            if (ql <= l && r <= qr) {
                apply(node, l, r, 1);
                return;
            }
            push(node, l, r);
            int mid = l + (r - l) / 2;
            update(node * 2, l, mid, ql, qr);
            update(node * 2 + 1, mid + 1, r, ql, qr);
            sum[node] = (
                sum[node * 2] + sum[node * 2 + 1]
            ) % MOD;
            sumSq[node] = (
                sumSq[node * 2] + sumSq[node * 2 + 1]
            ) % MOD;
        }
    public:
        SegmentTree(int size) : n(size) {
            sum.assign(4 * n, 0);
            sumSq.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }
        void update(int l, int r) {
            if (l <= r)
                update(1, 0, n - 1, l, r);
        }
        long long getSumSq() {
            return sumSq[1];
        }
    };
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree seg(n);
        unordered_map<int, int> last;
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            int p = last.count(nums[r])
                    ? last[nums[r]]
                    : -1;

            seg.update(p + 1, r);
            ans = (ans + seg.getSumSq()) % MOD;
            last[nums[r]] = r;
        }
        return ans;
    }
};
