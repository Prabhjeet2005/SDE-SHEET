#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {5, 3, 2, 1, 4}; // 7
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      for (int j = i + 1; j < arr.size(); j++)
      {
        if (arr[i] > arr[j])
          count += 1;
      }
    }
    cout << "Count Inversion Pairs: " << count << "\n";
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