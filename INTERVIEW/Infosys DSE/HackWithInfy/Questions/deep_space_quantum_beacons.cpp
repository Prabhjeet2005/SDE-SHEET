/*

### ⚔️ Blind Story-Stripping Challenge 7

**Problem: Deep-Space Quantum Beacons**

You are the lead engineer for the Infosys Deep-Space Network. You are tasked with placing exactly C quantum communication beacons along a straight asteroid belt.

You have mapped out N stable asteroids where a beacon can be safely placed. You are given an integer array `asteroids`, where `asteroids[i]` represents the exact coordinate (distance from the sun) of the i-th asteroid. **(Note: The coordinates might not be given in sorted order).**

Quantum beacons are highly unstable. If two beacons are placed too close to each other, their signals will jam. Therefore, you want to place the C beacons such that the **minimum distance** between any two adjacent beacons is as **large as possible** (you want to maximize the minimum distance).

Return this maximum possible minimum distance.

**Constraints:**
2 <= N <= 10^5
2 <= C <= N
1 <= asteroids[i] <= 10^9

*/

// SORT TO Put Actual Asteroid Order and check previous distance

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    int N = 5;
    int C = 3;
    vector<int> asteroids = {1, 2, 8, 4, 9};
    sort(asteroids.begin(), asteroids.end(), custom_compare);

    int start = 1, end = asteroids[N - 1] - asteroids[0];
    int beacons_distance = -1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (is_valid(mid, C, asteroids))
      {
        beacons_distance = mid;
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }

    cout<<"Maximizing Minimum Distance: "<<beacons_distance;
  }

private:
  bool static custom_compare(int a, int b)
  {
    return a < b;
  }

  bool is_valid(int mid, int C, vector<int> &asteroids)
  {
    int beacons_placed = 1;
    int last_placed = asteroids[0]; // Array index
    for (int i = 1; i < asteroids.size(); i++)
    {
      if (asteroids[i] - last_placed >= mid)
      {
        beacons_placed++;
        last_placed = asteroids[i];
      }
    }
    return beacons_placed >= C;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}