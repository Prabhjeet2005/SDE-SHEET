class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1)return s.size();
        int left = 0,right=0;
        unordered_set<int>set;
        int maxLength=-1;

        while(right < s.size()){
            while(set.find(s[right]) != set.end()){
                // FOUND IN SET
                set.erase(s[left]);
                left++;  
            }
            set.insert(s[right]);
            maxLength = max(maxLength,right-left+1);
            right++;
        }
        return maxLength;
    }
};