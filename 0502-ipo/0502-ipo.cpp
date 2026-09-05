class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> proj;
        for(int i = 0;i < capital.size();i++){
            proj.push_back({capital[i], profits[i]});
        }
    sort(proj.begin(), proj.end()); 
    priority_queue<int> pq;
    int idx = 0;
    while(k--){
       while(idx < proj.size() && proj[idx].first <= w) {
                pq.push(proj[idx].second);
                idx++;
            }
        if(pq.empty()){
            return w;
        }
        w = w + pq.top();
        pq.pop();
    }
    return w;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna