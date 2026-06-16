/*
***

### ⚔️ Blind Story-Stripping Challenge 15

 **Problem: The System-Wide Security Patch**

 You are the lead network administrator. A critical security vulnerability has been detected, and you must broadcast a security patch from the Main Server (Server 1) to the rest of the network.

 The network consists of N servers connected by M directed fiber-optic links. You are given an array `links`, where `links[i] = [U, V, T]` means it takes exactly T milliseconds for a data packet to travel from Server U to Server V.

 The patch is sent out simultaneously across all available links from Server 1. When a server receives the patch, it instantly forwards it to all of its connected neighbors.

 Find the **minimum total time** required for *every single server* in the network to receive the patch. If even one server is completely disconnected and can never receive the patch, return `-1`.

 **Constraints:**
 1 <= N <= 10^5
 1 <= M <= 2 x 10^5
 1 <= T <= 1000

**INPUT FORMAT:**
```text
4 3
1 2 100
1 3 10
3 4 40
```

**OUTPUT:**
```text
100
```
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution
{
  vector<vector<pair<int,int>>>adj_list;
  vector<int>dist;
  // Min Heap: {distance, node}
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
public:
  void solution(int N,int M, vector<vector<int>>&connections)
  {
    // ADJ_LIST: {weight,node}
    adj_list.resize(N+1);
    dist.resize(N+1,1e9);
    // MIN HEAP: {weight,node}
    for(auto &connection:connections){
      int u = connection[0],v = connection[1], w = connection[2];
      adj_list[u].push_back({w,v});
    }

    get_min_time();

    int maxi = -1;
    for(int i=1; i<=N; i++){
      maxi = max(maxi,dist[i]);
    }
    
    if(maxi == 1e9){
      cout<<"-1";
      return;
    }
    cout<<maxi;
  }
  private:
  void get_min_time(){
    dist[1] = 0;
    pq.push({0,1}); // {weight,node}

    while(!pq.empty()){
      auto top = pq.top();
      pq.pop();
      int curr_node = top.second;
      int curr_weight = top.first;

      if(curr_weight > dist[curr_node])continue;

      for(auto &neighbour: adj_list[curr_node]){
        int neighbor_node = neighbour.second;
        int neighbor_weight = neighbour.first;
        if(curr_weight + neighbor_weight < dist[neighbor_node]){
          dist[neighbor_node] = curr_weight + neighbor_weight;
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
  int N = 4,M = 3;
  vector<vector<int>> connections = {{1, 2, 100}, {1, 3, 10}, {3, 4, 40}}; 
  cout<<"\n";
  sol.solution(N,M,connections);
  cout<<"\n";
  cout << endl;
}