class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, res = 0 , n = nums.size();
        unordered_map<int,int>f;
        f[0] = 1;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
            int rem = sum % k;
            if(rem < 0){
                rem = rem + k;
            }
            res = res + f[rem];
            f[rem]++;
        }
        return res;
    }
};