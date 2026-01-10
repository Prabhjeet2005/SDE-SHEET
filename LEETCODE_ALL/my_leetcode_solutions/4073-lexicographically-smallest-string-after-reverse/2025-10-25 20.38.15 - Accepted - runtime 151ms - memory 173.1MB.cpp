class Solution {
public:
    string lexSmallest(string s) {
       string ans = s; 
        int n = s.size();

        for (int k = 1; k <= n; k++) {
            string temp = s; 
            reverse(temp.begin(), temp.begin() + k); 
            ans = min(ans, temp); 
        }

        for (int k = 1; k <= n; k++) {
            string temp = s; 
            reverse(temp.end() - k, temp.end()); 
            ans = min(ans, temp); 
        }

        return ans; 
    }
};