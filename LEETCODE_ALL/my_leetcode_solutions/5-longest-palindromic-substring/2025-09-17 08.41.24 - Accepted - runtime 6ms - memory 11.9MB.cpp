class Solution {
    pair<int, int> getMaxPalindromeLength(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, (right - 1) - (left + 1) + 1};
    }

public:
    string longestPalindrome(string s) {
        int maxLength = INT_MIN;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            // pair<start,length>
            pair<int, int> len1 =
                getMaxPalindromeLength(s, i, i); // ODD LENGTH
            pair<int, int> len2 =
                getMaxPalindromeLength(s, i, i + 1); // EVEN LENGTH

            int currentMaxLength = max({len1.second, len2.second});

            if (currentMaxLength > maxLength) {
                maxLength = currentMaxLength;
                if (len1.second == currentMaxLength) {
                    ans = s.substr(len1.first, len1.second);
                } else {
                    ans = s.substr(len2.first, len2.second);
                }
            }
        }
        return ans;
    }
};