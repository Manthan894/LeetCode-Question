class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }
        struct cmp {
            bool operator()(const pair<int, string>& a,const pair<int, string>& b) const {
                if (a.first == b.first) {
                    return a.second < b.second;
                }
                return a.first > b.first;
            }
        };
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            cmp
        > pq;
        for (const auto& [word, f] : freq) {
            pair<int, string> curr = {f, word};
            if (pq.size() < k) {
                pq.push(curr);
            }
            else if (curr.first > pq.top().first ||
                     (curr.first == pq.top().first &&
                      curr.second < pq.top().second)) {
                pq.pop();
                pq.push(curr);
            }
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
