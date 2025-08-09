#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 4, 5};

    // APPROACH 2
    // int temp = arr[0];
    // arr.erase(arr.begin());
    // arr.push_back(temp);

    int firstElement = arr[0];
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
    arr[n-1] = firstElement; 

    for (auto &it : arr)
    {
      cout << it << ", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}