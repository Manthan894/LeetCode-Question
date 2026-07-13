class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> new_interval;
        int n = intervals.size() , start = newInterval[0];  
        bool insert = false;
        for(int i=0;i<n;i++){
            if(insert == false && start <= intervals[i][0]){
                new_interval.push_back(newInterval);
                insert = true;
            }
            new_interval.push_back(intervals[i]);
        }
        if(!insert){
            new_interval.push_back(newInterval);
        }

        vector<vector<int>> res;
        int start1 = new_interval[0][0] , end1 = new_interval[0][1];
        for(int i=1;i<n+1;i++){
            int start2 = new_interval[i][0];
            int end2 = new_interval[i][1];
            if(start2 <= end1){
                start1 = start1;
                end1 = max(end1,end2);
                continue;
            }
            else{
                res.push_back({start1,end1});
                start1 = start2;
                end1 = end2;
            }
        }
        res.push_back({start1,end1});
        return res;
    }
};