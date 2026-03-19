/*
### ⚔️ Blind Story-Stripping Challenge 17 (The Decoy)

 **Problem: The Galactic Bank Heist**

 You are a cyber-thief infiltrating the central server of the Galactic Bank. The server grid consists of N security nodes, rooted at Node 1 (your entry point). You need to reach the Main Vault at Node N.

 The grid is defended by M laser-tripwire corridors. You are given an array `corridors`, where `corridors[i] = [U, V, C]` means sneaking from Node U to Node V takes C seconds.

 You also have a specialized hacking tool that creates W "Blindspots" in the security grid. You are given an array `blindspots`, where `blindspots[i] = [U, V]`. A blindspot allows you to instantly teleport from Node U to Node V. Because it is a teleport, it takes **exactly 0 seconds**.

 Find the minimum possible time to reach Node N. If it is impossible, return `-1`.

 **Constraints:**
 1 <= N <= 10^5
 1 <= M <= 2 x 10^5
 1 <= W <= 10^5
 1 <= C <= 1000

 INPUT FORMAT
 Line 1: Three space-separated integers: N (Security Nodes), M (Corridors), and W (Blindspots).
 Next M lines: Three space-separated integers U, V, C representing a corridor from U to V that takes C seconds.
 Next W lines: Two space-separated integers U, V representing a blindspot teleport from U to V (takes 0 seconds).

INPUT:
5 4 1
1 2 10
2 3 10
3 5 10
4 5 5
2 4

OUTPUT:
15

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  vector<vector<pair<int,int>>>adj_list;
  vector<int>dist;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
public:
  void solution(int N,int M,int W,vector<vector<int>>&corridors)
  {
    adj_list.resize(N+1);
    dist.resize(N+1,1e9);
    // {weight,node}
    for(auto &corridor:corridors){
      int u = corridor[0], v = corridor[1], w = corridor[2];
      adj_list[u].push_back({w,v});
    }

    get_min_time();

    dist[N] == 1e9 ? cout<<"-1" : cout<<dist[N];
  }
  private:
  void get_min_time(){
    dist[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
      auto top = pq.top();
      pq.pop();
      int curr_node = top.second;
      int curr_weight = top.first;

      if(curr_weight > dist[curr_node])continue;

      for(auto &neighbor:adj_list[curr_node]){
        int neighbor_node = neighbor.second;
        int neighbor_weight = neighbor.first;

        if(dist[curr_node] + neighbor_weight < dist[neighbor_node]){
          dist[neighbor_node] = dist[curr_node] + neighbor_weight;
          pq.push({dist[neighbor_node],neighbor_node});
        }
      }
    }
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  int N,M,W;
  cin>>N>>M>>W;
  vector<vector<int>>corridors;
  vector<vector<int>>blindspots;
  for(int i=0; i<M; i++){
    int u,v,c;
    cin>>u>>v>>c;
    corridors.push_back({u,v,c});
  }
  for(int i=0; i<W; i++){
    int u,v;
    cin>>u>>v;
    corridors.push_back({u,v,0});
  }
  sol.solution(N,M,W,corridors);
  cout << endl;
}