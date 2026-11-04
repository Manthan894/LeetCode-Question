class Solution {
public:
//Sliding Window + Median to calculate the minimum operations needed for each subarray of size x.
//Dynamic Programming to select exactly k non-overlapping subarrays with minimum total cost.
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = 1e18;
        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;
        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }
            if (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;

                high.insert(v);
                sumHigh += v;
            }
            if (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;
                low.insert(v);
                sumLow += v;
            }
        };
        auto remove = [&](int val) {
            auto it = low.find(val);
            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }
            if (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;
                high.insert(v);
                sumHigh += v;
            }
            if (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;
                low.insert(v);
                sumLow += v;
            }
        };
        auto getCost = [&]() -> long long {
            long long median = *low.rbegin();
            return median * (long long)low.size() - sumLow + sumHigh - median * (long long)high.size();
        };
        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);
        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);
            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }
            prev.swap(curr);
        }
        return prev[n];
    }
};
