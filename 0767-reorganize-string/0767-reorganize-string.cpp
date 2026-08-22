class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, char>& a,
                        const pair<int, char>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
    string reorganizeString(string s) {
        unordered_map<char, int> f;
        for (char c : s) {
            f[c]++;
        }
        priority_queue<pair<int, char>,
                       vector<pair<int, char>>,
                       cmp> pq;
        for (auto& p : f) {
            pq.push({p.second, p.first});
        }
        string res = "";
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (res.empty() || res.back() != p.second) {
                res.push_back(p.second);
                p.first--;
                if (p.first > 0) {
                    pq.push(p);
                }
            }
            else {
                if (pq.empty()) {
                    return "";
                }
                auto p1 = pq.top();
                pq.pop();
                res.push_back(p1.second);
                p1.first--;
                if (p1.first > 0) {
                    pq.push(p1);
                }
                pq.push(p);
            }
        }
        return res;
    }
};
