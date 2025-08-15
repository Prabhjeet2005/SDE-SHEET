#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4, 4, 2, 4, 3, 4, 4, 3, 2, 4};
    int majorityElement = arr[0];
    int count = 0;

    for(int i=1;i<arr.size();i++){
      if(majorityElement == arr[i]){
        count++;
      }else if(majorityElement != arr[i] && count > 0){
        count--;
      }

      if(count == 0){
        majorityElement = arr[i];
        count++;
      }
    }
    
    cout << "Majority Element: " << majorityElement << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}