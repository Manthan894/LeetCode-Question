#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            else if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            }
            else {
                st.push_back(token);
            }
        }
        string result = "";
        for (const string& dir : st) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};