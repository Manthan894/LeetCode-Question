class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int mx = 0;
        for (int x : nums) {
            sum += x;
            mx = max(mx, x);
        }
        return mx * nums.size() - sum;
    }
};