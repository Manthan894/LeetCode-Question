class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0] , maxending = nums[0] , minending = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int n1 = nums[i];
            int n2 = maxending * nums[i];
            int n3 = minending * nums[i];
            maxending = max(n1,max(n2,n3));
            minending = min(n1,min(n2,n3));
            res = max(res,max(maxending,minending));
        }
        return res;
    }
};