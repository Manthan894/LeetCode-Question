class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto& p : freq) {
            pq.push({p.second, p.first});
        }
        queue<tuple<int, char, int>> cooldown;
        int time = 0;
        while (!pq.empty() || !cooldown.empty()) {
            if (!cooldown.empty() &&
                get<2>(cooldown.front()) == time) {
                auto [count, task, availableTime] = cooldown.front();
                cooldown.pop();
                pq.push({count, task});
            }
            if (!pq.empty()) {
                auto [count, task] = pq.top();
                pq.pop();
                count--;
                time++;
                if (count > 0) {
                    cooldown.push({
                        count,
                        task,
                        time + n
                    });
                }

            }
            else {
                time++;
            }
        }
        return time;
    }
};
