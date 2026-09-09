class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> lo, hi;
        auto balance = [&]() {
            while (lo.size() > hi.size() + 1) {
                auto it = prev(lo.end());
                hi.insert(*it);
                lo.erase(it);
            }
            while (lo.size() < hi.size()) {
                auto it = hi.begin();
                lo.insert(*it);
                hi.erase(it);
            }
        };
        auto add = [&](int x) {
            if (lo.empty() || x <= *lo.rbegin())
                lo.insert(x);
            else
                hi.insert(x);

            balance();
        };
        auto remove = [&](int x) {
            auto it = lo.find(x);

            if (it != lo.end())
                lo.erase(it);
            else
                hi.erase(hi.find(x));

            balance();
        };
        for (int i = 0; i < k; i++)
            add(nums[i]);
        for (int i = k; ; i++) {
            if (k % 2 == 1) {
                ans.push_back((double)*lo.rbegin());
            } else {
                ans.push_back(
                    ((double)*lo.rbegin() + (double)*hi.begin()) / 2.0
                );
            }
            if (i == nums.size()){
                break;
            }
            remove(nums[i - k]);
            add(nums[i]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna