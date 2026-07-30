class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        if(nums[n-1] >= nums[0]){
            return nums[0];
        }
        int left = 0;
        int right = n - 1;
        int res = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= nums[n-1]){
                res = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return nums[res];
    }
};