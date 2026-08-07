class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = n - 1;
        int ans = 0;
        while (low <= high) {
            int guess = low + (high - low) / 2;
            int h = n - guess;
            if (citations[guess] >= h) {
                ans = h;
                high = guess - 1;
            }
            else {
                low = guess + 1;
            }
        }
        return ans;
    }
};