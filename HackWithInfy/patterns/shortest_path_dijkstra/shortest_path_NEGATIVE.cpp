/*

### ⚔️ Blind Story-Stripping Challenge 16 (The "Medium/Hard" Graph Trap)

 **Problem: The Unstable Quantum Wormholes**

 You are navigating a spaceship through a treacherous sector of space containing N space stations.
 There are M standard flight paths connecting these stations. You are given an array `flights`, where `flights[i] = [U, V, T]` means a standard flight from Station U to Station V takes T hours.

 However, there are also W experimental quantum wormholes. You are given an array `wormholes`, where `wormholes[i] = [U, V, T]`. These wormholes instantly teleport you from Station U to Station V, but they actually **rewind time** by T hours! (Represented as a negative cost: -T).

 You start at Station 1. You want to find the absolute minimum time required to reach Station N.

 **CRITICAL WARNING:** It is possible that a sequence of wormholes and flights creates a "Time Paradox" (a cycle where you can keep looping infinitely to gain infinite negative time). If a Time Paradox exists *anywhere* in the sector that you can reach, return `-1`. Otherwise, return the minimum time to reach Station N.

 **Constraints:**
 1 <= N <= 2000
 1 <= M, W <= 5000
 1 <= T <= 10^4

**INPUT FORMAT:**
```text
3 1 1      // N=3, Flights=1, Wormholes=1
1 2 5      // Flight: 1 to 2 takes 5
2 3 10     // Wormhole: 2 to 3 rewinds 10 (cost = -10)
```
*(Explanation: 1 -> 2 takes 5. 2 -> 3 takes -10. Total time to 3 is -5).*

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution(int N, int F, int W, vector<vector<int>> &flights, vector<vector<int>>&wormholes)
  {
    vector<int>dist(N+1,1e9);
    dist[1]=0; // FIX: Starting Node distance is 0
    // Relax/Update N-1 Times
    for(int i=0; i<N-1; i++){
      for(auto &flight: flights){
        int u = flight[0],v = flight[1], w = flight[2];
        if(dist[u] != 1e9 && dist[u] + w < dist[v]){
          dist[v] = dist[u] + w;
        }
      }
      for(auto &wormhole: wormholes){
        int u = wormhole[0], v = wormhole[1], w = -wormhole[2];
        if (dist[u] != 1e9 && dist[u] + w < dist[v])
        {
          dist[v] = dist[u] + w;
        }
      }
    }

    // RELAX/UPDATE 1 more time -> -ve Cyle Present
    bool negative_cycle = false;
    for (auto &flight : flights)
    {
      int u = flight[0], v = flight[1], w = flight[2];
      if (dist[u] != 1e9 && dist[u] + w < dist[v])
      {
        negative_cycle = true;break;
      }
    }
    for (auto &wormhole : wormholes)
    {
      int u = wormhole[0], v = wormhole[1], w = -wormhole[2];
      if (dist[u] != 1e9 && dist[u] + w < dist[v] && !negative_cycle)
      {
        negative_cycle = true;break;
      }
    }

    if(negative_cycle){
      cout<<"-1";
      return;
    }
    cout<<dist[N];
  }
};

int main()
{
  cout << endl;
  int N = 3, F= 1,W= 1; // N=3, Flights=1, Wormholes=1
  vector<vector<int>>flights = {{1, 2, 5}};     // Flight: 1 to 2 takes 5
  vector<vector<int>> wormholes = {{2, 3, 10}};
  Solution sol = Solution();
  sol.solution(N,F,W,flights,wormholes);
  cout << endl;
}