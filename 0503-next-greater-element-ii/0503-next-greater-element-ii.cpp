class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() and s.top() <= nums[i%n]){
                s.pop();
            }
            if(s.empty()){
                if(i < n){
                    res[i] = -1;
                }
            }
            else{
                if(i<n){
                res[i] = s.top();
                }
            }
            s.push(nums[i%n]);
        }
        return res;
    }
};