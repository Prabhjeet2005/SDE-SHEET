#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int cows = 4, size = arr.size();
    sort(arr.begin(), arr.end());
    int mini = arr[0], maxi = arr[size - 1], maxDistance = maxi - mini;
    int ans = maxDistance;

    if (cows > size)
    {
      cout << "Not Possible";
      return;
    }

    int start = 0,end = maxDistance;

    while(start <= end){
      int mid = start + (end - start)/2;

      int currentCowCount = 1,lastCowPosition = 0;
      for(int i=1;i<size;i++){
        if(arr[i] - arr[lastCowPosition] >= mid){
          lastCowPosition = i;
          currentCowCount++;
        }
      }
      if(currentCowCount >= cows){
        ans = mid;
        start = mid+1;
      }else{
        end = mid-1;
      }
    }


    cout << "Min Possible Max Distance: " << ans;
  }
};

int main()
{
  Solution solObj = Solution();
  cout << "\n";
  solObj.solution();
  cout << "\n";
}