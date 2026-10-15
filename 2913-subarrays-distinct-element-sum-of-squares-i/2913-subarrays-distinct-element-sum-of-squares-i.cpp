class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<long long> cnt(n + 1), tot(n + 1);  
        unordered_map<int, int> last;
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            int p = last.count(nums[r]) ? last[nums[r]] : -1;
            long long c = 0, s = 0;
            for (int i = n - p - 1; i > 0; i -= i & -i) 
                c += cnt[i], s += tot[i];
            ans += (long long)(n - r) * ((long long)(r - p) * (r - p) - 2 * (s - p * c));
            for (int i = n - p; i <= n; i += i & -i)  
                cnt[i]++, tot[i] += p;
            last[nums[r]] = r;
        }
        return ans;
    }
};
/*An Example taken from the leetcode for better understanding of problem
Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.*/
