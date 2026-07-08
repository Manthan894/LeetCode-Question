class Solution {
    bool correct(int freq_s[], int freq_t[]) {
        for(int i = 0; i < 256; i++) {
            if(freq_s[i] < freq_t[i])
            return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int low = 0;
        int start = 0;
        int res = INT_MAX;
        int freq_s[256] = {0};
        int freq_t[256] = {0};
        for(char c : t){
            freq_t[(unsigned char)c]++;
        }
        for(int high = 0; high < s.size(); high++) {
            freq_s[(unsigned char)s[high]]++;
            while(correct(freq_s, freq_t)) {
                int len = high - low + 1;
                if(len < res) {
                    res = len;
                    start = low;
                }
                freq_s[(unsigned char)s[low]]--;
                low++;
            }
        }
        if(res == INT_MAX){
            return "";
        }
        return s.substr(start, res);
    }
};