class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        stations.push_back({target, 0});
        int fuel = startFuel;
        int prev = 0;
        int stops = 0;
        for (auto& station : stations) {
            int position = station[0];
            int stationFuel = station[1];
            fuel -= (position - prev);
            while (fuel < 0 && !maxHeap.empty()) {
                fuel += maxHeap.top();
                maxHeap.pop();
                stops++;
            }
            if (fuel < 0) {
                return -1;
            }
            maxHeap.push(stationFuel);
            prev = position;
        }
        return stops;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna