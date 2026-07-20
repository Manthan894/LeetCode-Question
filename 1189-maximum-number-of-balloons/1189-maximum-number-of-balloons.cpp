class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> have;
        unordered_map<char,int> need;
        for(int i=0;i<text.size();i++){
            have[text[i]]++;
        }
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;
        int res = INT_MAX;
        for(auto i : need){
            char c  = i.first;
            int f1 = i.second;
            int f2 = have[c];
            int times = f2/f1;
            res = min(res,times);
        }
        return res;
    }
};