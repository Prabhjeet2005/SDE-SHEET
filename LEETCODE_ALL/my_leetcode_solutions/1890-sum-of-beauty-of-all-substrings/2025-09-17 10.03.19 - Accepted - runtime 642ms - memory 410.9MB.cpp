class Solution {
  int getCurrentBeauty(int freq[])
  {
    int maxFreq = INT_MIN, minFreq = INT_MAX;
    for (int i = 0; i < 26; i++)
    {
      if (freq[i] == 0)
        continue;
      maxFreq = max(maxFreq, freq[i]);
      minFreq = min(minFreq, freq[i]);
    }
    return maxFreq - minFreq;
  }

public:
    int beautySum(string s) {
        int beautyAll = 0;

        for (int i = 0; i < s.size(); i++) {
            int freq[26] = {0};
            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;
                string curr = s.substr(i, j - i + 1);
                int currentBeauty = getCurrentBeauty(freq);
                if (currentBeauty > 0) {
                    beautyAll += currentBeauty;
                }
            }
        }
        return beautyAll;
    }
};