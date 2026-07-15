class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char,int>> st;
        string res = "";
        for(int i=0;i<n;i++){
            char c = s[i];
            if(st.empty()){
                st.push({c,1});
                continue;
            }
            if(st.top().first != c){
                st.push({c,1});
                continue;
            }
            if(st.top().second < k-1){
                pair<char,int> t = st.top();
                st.pop();
                st.push({t.first,t.second+1});
                continue;
            }
            st.pop();
        }
        while(!st.empty()){
            pair<char,int> t1 = st.top();
            st.pop();
            while(t1.second!=0){
                res.push_back(t1.first);
                t1.second--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};