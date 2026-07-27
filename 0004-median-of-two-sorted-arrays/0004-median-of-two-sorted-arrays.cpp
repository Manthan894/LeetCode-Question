class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        vector<int> store;
        int i = 0 , j = 0;
        int m = nums1.size() , n = nums2.size();
        while(i < m && j < n){
            if(nums1[i] > nums2[j]){
                store.push_back(nums2[j]);
                j++;
            }
            else if(nums1[i] < nums2[j]){
                store.push_back(nums1[i]);
                i++;
            }
            else{ 
                store.push_back(nums1[i]);
                store.push_back(nums2[j]);
                j++;
                i++;
            } 
        }
        if(i < m){
            while(i < m){
                store.push_back(nums1[i]);
                i++;
            }
        }
        if(j < n){
            while(j < n){
                store.push_back(nums2[j]);
                j++;
            }
        }
        int size = store.size();
        if(store.size()%2 == 0){
            int mid1 = size/2;
            int mid2 = mid1 - 1;
            res = (store[mid1] + store[mid2]) / 2.0;
            return res;
        }
        else{
            int mid = (size - 1)/2;
            res = static_cast<double>(store[mid]);
            return res;
        }
    }
};