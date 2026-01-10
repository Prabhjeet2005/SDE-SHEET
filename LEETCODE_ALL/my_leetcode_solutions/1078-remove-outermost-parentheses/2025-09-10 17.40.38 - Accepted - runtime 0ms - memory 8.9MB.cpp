class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int paranthesisCount = 0;

        for (char& ch : s) {
            if (ch == '(') {
                if (paranthesisCount != 0)
                    ans += "(";
                paranthesisCount++;
            } else {
                if (paranthesisCount > 1)
                    ans += ")";
                paranthesisCount--;
            }
        }
        return ans;
    }
};