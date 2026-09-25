#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) {
            return {}; 
        }
        unordered_set<string> seen;
        unordered_set<string> ans;
        for (int i = 0; i <= s.length() - 10; ++i) {
            string current = s.substr(i, 10);
            if (seen.count(current)) {
                ans.insert(current);
            } else {
                seen.insert(current);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};