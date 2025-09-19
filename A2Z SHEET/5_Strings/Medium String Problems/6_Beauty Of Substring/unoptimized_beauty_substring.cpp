#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
  int getCurrentBeauty(string &str)
  {
    int freq[26] = {0};
    for (auto ch : str)
    {
      freq[ch - 'a']++;
    }
    int maxFreq = INT_MIN, minFreq = INT_MAX;
    for (int i = 0; i < 26; i++)
    {
      if(freq[i]==0)continue;
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

    for (int i = 0; i < str.size() - 1; i++)
    {
      for (int j = i + 1; j < str.size(); j++)
      {
        string curr = str.substr(i, j - i + 1);
        int currentBeauty = getCurrentBeauty(curr);
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