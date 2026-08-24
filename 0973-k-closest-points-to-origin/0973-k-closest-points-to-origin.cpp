class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            int da = a[0] * a[0] + a[1] * a[1];
            int db = b[0] * b[0] + b[1] * b[1];
            return da < db;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            cmp
        > pq;
        for (auto &point : points) {
            pq.push(point);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
