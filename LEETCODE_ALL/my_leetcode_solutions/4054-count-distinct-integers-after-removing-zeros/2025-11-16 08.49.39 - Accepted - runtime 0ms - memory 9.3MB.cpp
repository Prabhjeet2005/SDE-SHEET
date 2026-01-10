class Solution {
    long long dp[17]; 

    long long get_ans(int k) {
        if (k == 0) return 1;

        if (dp[k] != 0) return dp[k];

        dp[k] = 9 * get_ans(k - 1);

        return dp[k];

    }

    long long solve(string& s, int i, bool is_tight) {
        if (i == s.length()) {
            return 1;
        }

        long long count = 0;

        int limit = is_tight ? (s[i] - '0') : 9;



        for (int d = 1; d <= 9; ++d) {

            if (d > limit) {

                break;

            }
            if (d < limit) {
                count += get_ans(s.length() - i - 1);
            } else {
                count += solve(s, i + 1, is_tight);
            }
        }
        return count;
    }
public:
    long long countDistinct(long long n) {
        string str = to_string(n);
        int length = str.length();
        long long tc = 0;
        for(int i=0; i<17; i++)dp[i]=0;

        for(int i=1; i<length; i++){
            tc += get_ans(i);
        }
        tc+= solve(str,0,true);
        return tc;
    }
};