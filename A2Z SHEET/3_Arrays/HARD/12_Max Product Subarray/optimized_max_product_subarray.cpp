#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, -3, 0, -4, -5}; // 20
    long long prefixProduct = arr[0], suffixProduct = arr[0], maxProduct = arr[0];
    bool allZero = true;
    for (int i = 0; i < arr.size(); i++)
    {
      if(prefixProduct == 0){
        prefixProduct = 1;
      }
      if(suffixProduct == 0){
        suffixProduct = 1;
      }
      allZero = false;
      prefixProduct *= arr[i];
      suffixProduct *= arr[arr.size()-i-1];
      maxProduct = max({maxProduct, suffixProduct,prefixProduct});
    }
    if(allZero){
      cout<<"Max Product Subarray: "<<0;
      return;
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