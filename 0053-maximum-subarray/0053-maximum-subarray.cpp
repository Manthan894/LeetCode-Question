class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0] , best_answer = nums[0];
        for(int i = 1;i<nums.size();i++){
            int v1 = best_answer + nums[i];
            int v2 = nums[i];
            best_answer = max(v1,v2);
            res = max(res,best_answer);
        }
        return res;
    }
};