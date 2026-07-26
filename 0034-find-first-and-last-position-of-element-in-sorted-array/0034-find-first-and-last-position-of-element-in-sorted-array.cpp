class Solution {
public:
int First(vector<int>& nums,int target){
    int left = 0 , right = nums.size() - 1 , res = -1;
    while(left <= right){
        int mid = (left + right)/2;
        if(nums[mid] < target){
            left = mid + 1;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            res = mid;
            right = mid - 1;
        }
    }
    return res;
}
int last(vector<int>& nums,int target){
    int left = 0 , right = nums.size() - 1 , res = -1;
    while(left <= right){
        int mid = (left + right)/2;
        if(nums[mid] < target){
            left = mid + 1;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            res = mid;
            left = mid + 1;
        }
    }
    return res;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int F = First(nums,  target);
        int L = last(nums,  target);
        vector<int>result;
        result.push_back(F);
        result.push_back(L);
        return result;
    }
};