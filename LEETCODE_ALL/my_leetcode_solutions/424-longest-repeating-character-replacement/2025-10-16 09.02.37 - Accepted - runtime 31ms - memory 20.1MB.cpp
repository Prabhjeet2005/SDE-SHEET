class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        priority_queue<pair<int,char>>maxHeap;
        int left = 0, maxFreq = 0;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            maxHeap.push({freq[s[i]],s[i]});
            while(left <= i && (i - left + 1) - maxHeap.top().first > k){
                freq[s[left]]--;
                left++;
            }
            // Valid Window ==>  (windowSize - currentCharFreq) AKA (other
            // characters except current) <= k
            if ((i - left + 1) - maxHeap.top().first <= k) {
                maxFreq = max(maxFreq, i - left + 1);
            }
        }

        return maxFreq;
    }
};