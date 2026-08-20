class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<int> res;
        struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
           if(a.first == b.first){
               return a.second > b.second;
           }   
           return a.first > b.first;        
           }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp > pq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(auto i:freq){
            int ele = i.first;
            int f = i.second;
            pair<int,int> curr = {f,ele};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first < pq.top().first){
                continue;
            }
            pq.pop();
            pq.push(curr);
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};