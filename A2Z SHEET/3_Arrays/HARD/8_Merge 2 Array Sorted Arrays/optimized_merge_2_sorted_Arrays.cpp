#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    int ptr1 = arr1.size()-1, ptr2 = 0;
    while (ptr1 >=0 && ptr2 < arr2.size())
    {
      if(arr1[ptr1] <= arr2[ptr2]){
        break;
      }
      swap(arr1[ptr1--],arr2[ptr2++]);
    }
   sort(arr1.begin(),arr1.end());
   sort(arr2.begin(),arr2.end());


    for (auto &element : arr1)
    {
      cout << element << ", ";
    }
    cout<<"\n";
    for (auto &element : arr2)
    {
      cout << element << ", ";
    }
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