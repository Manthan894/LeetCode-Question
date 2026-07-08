class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int low = 0 , high = 0 , n = s.size() , k = p.size() , len = high - low + 1;
        vector<int> store;
        vector<int>freqs(26,0);
        vector<int>freqp(26,0);
        if(k > n){
            return store;
        }
        for(char c: p){
            freqp[c - 'a']++;
        }
        for(high = 0;high < n;high++){
            freqs[s[high] - 'a']++;
            len = high - low + 1;
            if(len > k){
                freqs[s[low] - 'a']--;
                low++;
                len = high - low + 1;
            }
            if(len == k){
                if(freqs == freqp){
                    store.push_back(low);
                }
            }
        }
        return store;
    }
};