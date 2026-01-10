class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        long long ans = 0;

        for (auto& ch : s) {
            if (ch != ' ') {
                break;
            }
            idx++;
        }

        bool isPositive = true;
        if (s[idx] == '-') {
            isPositive = false;
            idx++;
        } else if (s[idx] == '+') {
            idx++;
        }
        int sign = isPositive ? +1 : -1;

        while (idx < s.size()) {
            if (s[idx] - '0' >= 0 && s[idx] - '0' <= 9) {
                ans = (ans * 10) + (s[idx] - '0') * sign ;
                if(ans > INT_MAX)ans = INT_MAX;
                if(ans < INT_MIN)ans = INT_MIN;
                idx++;
            }else{
                break;
            }
        }
        return ans;

    }
};