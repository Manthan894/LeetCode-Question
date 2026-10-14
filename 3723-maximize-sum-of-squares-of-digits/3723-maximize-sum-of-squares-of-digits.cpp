
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9LL * num) return "";

        string res;
        res.reserve(num);
        res.append(sum / 9, '9');
        int rem = sum % 9;
        if (rem > 0) {
            res.push_back('0' + rem);
        }
        res.append(num - res.size(), '0');
        return res;
    }
};
