class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> stack;
        int total_length = s.size(), count_a = 0,count_b=0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i]=='a')count_a++;
            else count_b++;
        }

        

        return abs(count_a-count_b);
    }
};