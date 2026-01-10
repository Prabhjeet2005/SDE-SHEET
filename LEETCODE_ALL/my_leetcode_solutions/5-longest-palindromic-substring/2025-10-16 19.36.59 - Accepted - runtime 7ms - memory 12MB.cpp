class Solution {
    pair<int,int> getMaxSubstr(string &s,int left,int right){
        while(left >=0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return {left+1, (right-1) - (left+1) + 1};
    }
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        string longestStr = "";

        for(int currentCharIndex=0;currentCharIndex<s.size();currentCharIndex++){
            // <startIdx,lengthSubstr>
            pair<int,int> evenLength = getMaxSubstr(s,currentCharIndex,currentCharIndex);
            pair<int,int> oddLength = getMaxSubstr(s,currentCharIndex,currentCharIndex+1);
            int currentLength = max(evenLength.second,oddLength.second);
            if(maxLength < currentLength){
                maxLength = currentLength;
                if(evenLength.second == maxLength){
                    longestStr = s.substr(evenLength.first,evenLength.second);
                }else{
                    longestStr = s.substr(oddLength.first,oddLength.second);
                }
            }
        }

        return longestStr;
    }
};