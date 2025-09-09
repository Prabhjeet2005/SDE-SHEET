#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {3, 4};
    int n1 = arr1.size(), n2 = arr2.size();
    int count1 = (n1 + n2) / 2, count2 = count1 - 1, element1 = -1, element2 = -1;
    int i = 0, j = 0, ptr = 0;

    while (i < n1 && j < n2)
    {
      if (arr1[i] < arr2[j])
      {
        if (ptr == count1)
          element2 = arr1[i];
        if (ptr == count2)
          element1 = arr1[i];
        i++;
        ptr++;
      }
      else
      {
        if (ptr == count1)
          element2 = arr2[j];
        if (ptr == count2)
          element1 = arr2[j];
        j++;
        ptr++;
      }
    }
    while (i < n1)
    {
      if (ptr == count1)
        element2 = arr1[i];
      if (ptr == count2)
        element1 = arr1[i];
      i++;
      ptr++;
    }
    while (j < n2)
    {
      if (ptr == count1)
        element2 = arr2[j];
      if (ptr == count2)
        element1 = arr2[j];
      j++;
      ptr++;
    }
    double ans = -1;
    if ((n1 + n2) % 2 == 1)
    {
      ans = (double)element2;
    }
    else
    {
      ans = (double)(element1 + element2) / (double)2;
    }

    cout << "Median Of 2 Sorted Arrays: " << ans;
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