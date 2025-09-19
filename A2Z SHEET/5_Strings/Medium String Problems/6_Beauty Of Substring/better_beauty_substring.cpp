#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
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
  void solution()
  {
    string str = "aabcbaa";
    int beautyAll = 0;

    for (int i = 0; i < str.size(); i++)
    {
      int freq[26] = {0};
      for (int j = i; j < str.size(); j++)
      {
        freq[str[j] - 'a']++;
        string curr = str.substr(i, j - i + 1);
        int currentBeauty = getCurrentBeauty(freq);
        if (currentBeauty > 0)
        {
          beautyAll += currentBeauty;
        }
      }
    }
    cout << "Beauty Of All Substrings: " << beautyAll;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}