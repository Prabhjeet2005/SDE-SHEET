#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 5, 1, 3, 0};
    int n = arr.size();

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      maxi = max(maxi, arr[i]);
    }

    cout << "Largest element : " << maxi << endl;  
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
}