class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreqChar = 0,maxLengthSubstr = 0,currWindowSize = 0,left=0;
        unordered_map<char,int>freqMap; // WORST CASE -> 26 size O(1)

        for(int right = 0;right < s.size();right++){
            freqMap[s[right]]++;
            currWindowSize++;
            for(auto & iterator:freqMap){
                maxFreqChar = max(maxFreqChar,iterator.second);
            }
            while(currWindowSize - maxFreqChar > k){
                // INVALID WINDOW
                currWindowSize--;
                freqMap[s[left]]--;
                left++;
            }
            for(auto & iterator:freqMap){
                maxFreqChar = max(maxFreqChar,iterator.second);
            }

            if(currWindowSize - maxFreqChar <= k){
                maxLengthSubstr = max(maxLengthSubstr,currWindowSize);
            }

        }
        return maxLengthSubstr;
    }
};