class Solution {
public:

    vector<string> ans;

    vector<string> keypad = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void solve(int index, string &digits, string &curr){

        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }

        string letters = keypad[digits[index] - '0'];

        for(char ch : letters){
            curr.push_back(ch);
            solve(index + 1, digits, curr);
            curr.pop_back();      // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()){
            return {};
        }

        string curr = "";

        solve(0, digits, curr);

        return ans;
    }
};