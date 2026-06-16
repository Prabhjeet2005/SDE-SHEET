/*

### ⚔️ Final Exam: Challenge 3 (The Accumulating Limit)

**Problem: The Lunar Solar Grid**
You manage a lunar solar panel array for N hours. You are given an array `sunlight`, where `sunlight[i]` represents the megawatts of power generated during the i-th hour.

Each hour, you can either keep the panels **Active** (gaining `sunlight[i]` megawatts) or turn them **Offline** (gaining 0 megawatts).

The lunar dust storms are severe. If you leave the panels Active for **MORE THAN 2 consecutive hours**, the mechanics will jam and permanently break. Therefore, you can have a maximum of 2 consecutive Active hours before you are forced to turn them Offline for at least 1 hour to clean the dust.

Find the maximum power you can generate.

**Constraints:**
1 <= N <= 10^5
-10^4 <= sunlight[i] <= 10^4

**INPUT FORMAT:**
Line 1: N
Line 2: N integers representing `sunlight`

**Sample Input:**

5
10 20 30 40 50

**Sample Output:**

120

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution(int N, vector<int> &arr)
  {
    int active_hour1 = -1e9;
    int active_hour2 = -1e9;
    int offline = 0;

    for(int i=0; i<N; i++){
      int new_active_hour1 = offline + arr[i] ;       // Must Be Offline For 1st Hour
      int new_active_hour2 = active_hour1 + arr[i] ;  // Must be 2nd Consecutive Hour
      int new_offline = max({offline,active_hour1,active_hour2}) + 0 ;  // Can be at anytime

      active_hour1 = new_active_hour1;
      active_hour2 = new_active_hour2;
      offline = new_offline;
    }
    cout<<max({active_hour1,active_hour2,offline});
  }
};

int main()
{
  int N;
  cin >> N;
  vector<int> arr;
  for (int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  Solution sol = Solution();
  cout << endl;
  sol.solution(N, arr);
  cout << endl;
}