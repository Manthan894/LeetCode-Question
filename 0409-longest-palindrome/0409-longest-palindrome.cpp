class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> f;
        int n = s.size();
        int res = 0;
        bool odd = false;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        for(auto i:f){
            int val = i.second;
            if(val%2 == 0){
                res = res + val;
            }
            else{
                odd = true;
                res = res + val - 1;
            }
        }
        if(odd == false){
            return res;
        }
        else{
            return res + 1;
        }
    }
};