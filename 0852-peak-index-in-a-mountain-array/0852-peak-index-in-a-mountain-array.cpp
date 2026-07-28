class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size() , i = 0;
        while(i < n - 1){
            if(arr[i] < arr[i+1]){
                i++;
            }
            if(arr[i] > arr[i+1]){
                break;
            }
        }
        return i;
    }
};