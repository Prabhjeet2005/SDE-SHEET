class Solution {
public:
    int minOperations(string s) {
        int operations = 0;
        int maxDistance = INT_MIN;

        // if(s.size() == 1 && s[0] == 'a')return 0;

        for(int i=0; i<s.size();i++){
            int currentDistance1 = 'z' - s[i]; // Do + 1
            if(currentDistance1 == 25)currentDistance1 = -1;
            maxDistance = max(currentDistance1,maxDistance);
        }
        return maxDistance+1;
    }
};