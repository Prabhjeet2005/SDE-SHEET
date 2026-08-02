/*
Network Technician's Mission
Problem Description
In the city of Techville, a network technician named Sam is tasked with inspecting a newly
established network of communication towers.
The network is structured as a rooted tree with n towers, with the main control tower located
at node 1. This control tower serves as the central hub for all communications.
The network is built through various terrains, some of which are marked as hazardous
zones.
Each tower is either in a safe zone (1) or a hazardous zone (0).
The outermost towers (the leaf nodes of the tree) need to be inspected by Sam, but he is
cautious and wants to avoid paths that traverse through too many consecutive hazardous
zones.
Your task is to help Sam count the number of outermost towers (leaf nodes) he can safely
inspect, where the path from the main control tower to the leaf contains no more than M
consecutive hazardous zones.
It is guaranteed that the given set of edges forms a tree structure.
Function Description
Parameters:
N → number of nodes in the tree
M → maximum allowed consecutive hazardous zones
K → always equal to N-1
Arr1 → array of size N containing 0 or 1 for each node
Arr2 → edges of the tree
Constraints:
2 <= N <= 10^5
1 <= M <= N
K = N-1
Each element in Arr1 is either 0 or 1
Input Format:
First line contains N
Second line contains M
Third line contains K
Next N integers describe Arr1
Next K lines contain edges
Output Format:
Print the number of valid leaf nodes Sam can inspect.

INPUT:
5
2
4
0 0 1 0 0
1 2
2 3
1 4
4 5
OUTPUT:
1
*/

#include <iostream>
#include <vector>
using namespace std;

long long dfs(int curr, int parent, int m, vector<vector<pair<int, int>>> &adj, int count_hazard)
{
  if(count_hazard > m)return 0;
  bool is_leaf = true;
  long long count = 0;
  for(auto &neighbor:adj[curr]){
    int node = neighbor.first;
    int is_safe = neighbor.second;

    if(node == parent)continue;
    is_leaf = false;
    int curr_hazard = is_safe == 1 ? 0:count_hazard+1; // Safe then count resets
    count += dfs(node,curr,m,adj,curr_hazard);
  }
  if(is_leaf)return 1;
  return count;
}

int count_non_hazard_paths(int n, int m, int k, vector<int> &arr1, vector<vector<int>> &edges)
{
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0], v = edges[i][1];
    adj[u].push_back({v, arr1[v-1]});
    adj[v].push_back({u,arr1[u-1]});
  }
  long long count_path = 0;
  int root_hazard = arr1[0] == 0?1:0;
  count_path += dfs(1, -1, m, adj, root_hazard);

  return count_path;
}

int main()
{
  int n = 5, m = 2, k = 4;
  vector<int> arr1 = {0, 0, 1, 0, 0};
  vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 4}, {4, 5}};

  cout << count_non_hazard_paths(n, m, k, arr1, edges);
}