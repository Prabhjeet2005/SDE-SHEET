#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, -3, 0, -4, -5}; // 20
    long long currentProduct = 1, maxProduct = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
      currentProduct = 1;
      for (int j = i; j < arr.size(); j++)
      {
        currentProduct *= arr[j];
        maxProduct = max(maxProduct, currentProduct);
      }
    }

    cout << "Max Product: " << maxProduct;
  }
};

int main()
{
  Solution sol = Solution();
  cout << "\n";
  sol.solution();
  cout << "\n";
}