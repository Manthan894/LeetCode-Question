class Solution {
public:

    long helper(vector<int>& piles, int n, int speed) {
        long long hour = 0;
        for (int i = 0; i < n; i++) {
            hour += piles[i] / speed;
            if (piles[i] % speed != 0){
                hour++;
            }
        }
        return hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = -1;
        while (left <= right) {
            int speed = left + (right - left) / 2;
            long long hour1 = helper(piles, n, speed);
            if (hour1 > h) {
                left = speed + 1;
            }
            else {
                res = speed;
                right = speed - 1;
            }
        }
        return res;
    }
};