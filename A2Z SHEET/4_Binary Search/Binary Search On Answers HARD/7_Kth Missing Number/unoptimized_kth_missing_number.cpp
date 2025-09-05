#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    for (auto &element : arr)
    {
      if (element <= k)
        k++;
      else
        break;
    }

    cout << "Kth Missing Number: " << k;
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