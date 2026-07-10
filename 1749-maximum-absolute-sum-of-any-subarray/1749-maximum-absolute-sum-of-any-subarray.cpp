class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res = abs(nums[0]) , maxi = nums[0] , mini = nums[0];
        for(int i = 1;i<nums.size();i++){
            maxi = max(maxi + nums[i] , nums[i]);
            mini = min(mini + nums[i] , nums[i]);
            int temp = abs(mini);
            res = max(res,max(maxi,temp));
        }
        return res;
    }
};