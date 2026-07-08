class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int low = 0;
        int k = s1.size();  
        int n = s2.size();      
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        if (k > n)
            return false;
        for (char c : s1) {
            freq1[c - 'a']++;
        }
        for (int high = 0; high < n; high++) {
            freq2[s2[high] - 'a']++;
            if (high - low + 1 > k) {
                freq2[s2[low] - 'a']--;
                low++;
            }
            if (high - low + 1 == k) {
                if (freq1 == freq2)
                return true;
            }
        }
        return false;
    }
};