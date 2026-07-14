class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>res;
        int n = s.size();
        string ans;
        for(int i=0;i<n;i++){
            if(res.empty()){
                res.push(s[i]);
                continue;
            }
            if(s[i] == res.top()){
                res.pop();
                continue;
            }
                res.push(s[i]);
        }
        while(!res.empty()){
            ans.push_back(res.top());
            res.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};