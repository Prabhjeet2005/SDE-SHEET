#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {13, 2, 4, 67, 3, 66, 43};
    int n = arr.size();
    int largest = arr[0], second_largest = arr[0];
    int smallest = arr[0], second_smallest = arr[0];

    for (int i = 0; i < n; i++)
    {
      if (arr[i] > largest)
      {
        second_largest = largest;
        largest = arr[i];
      }
      else if (arr[i] < largest && arr[i] > second_largest)
      {
        second_largest = arr[i];
      }
      if (arr[i] <smallest)
      {
        second_smallest = smallest;
        smallest = arr[i];
      }
      else if (arr[i] > smallest && arr[i] < second_smallest)
      {
        second_smallest = arr[i];
      }
    }

    cout << "Largest Element In Array: " << largest << endl;
    cout << "Second Largest Element In Array: " << second_largest << endl;
    cout << "Smallest Element In Array: " << smallest << endl;
    cout << "Second Smallest Element In Array: " << second_smallest << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}