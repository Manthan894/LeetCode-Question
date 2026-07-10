class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noignore = arr[0] , ignore = INT_MIN , n ;
        int res = arr[0];
        for(int i=1;i<arr.size();i++){
            int pre_no = noignore;
            int pre_ig = ignore;
            noignore = max(pre_no + arr[i] , arr[i]);
            if(pre_ig == INT_MIN){
                ignore = pre_no;
            }
            else{
                ignore = max(pre_ig + arr[i], pre_no);
            }
            res = max(res,max(ignore,noignore));
        }
        return res;
    }
};