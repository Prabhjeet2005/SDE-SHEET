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

    vector<int> arr3(arr1.size() + arr2.size() - 2, 0);
    int ptr1 = 0, ptr2 = 0, ptr3 = 0;
    while (ptr1 < arr1.size() && ptr2 < arr2.size())
    {
      if (arr1[ptr1] < arr2[ptr2])
      {
        arr3[ptr3] = arr1[ptr1];
        ptr1++;
        ptr3++;
      }
      else
      {
        arr3[ptr3] = arr2[ptr2];
        ptr2++;
        ptr3++;
      }
    }

    while (ptr1 < arr1.size())
    {
      arr3[ptr3] = arr1[ptr1];
      ptr1++;
      ptr3++;
    }
    while (ptr2 < arr2.size())
    {
      arr3[ptr3] = arr2[ptr2];
      ptr2++;
      ptr3++;
    }
    long double median = -1;
    if ((arr1.size() + arr2.size()) % 2 == 1)
    {
      // odd
      int index = (arr3.size()) / 2;
      median = arr3[index];
    }
    else
    {
      int index1 = (arr3.size()) / 2;
      int index2 = ((arr3.size()) / 2) + 1;
      median = (long double)(arr3[index1] + arr3[index2]) / (long double)2;
    }

    cout << "Median Of 2 Sorted Arrays: " << median;
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