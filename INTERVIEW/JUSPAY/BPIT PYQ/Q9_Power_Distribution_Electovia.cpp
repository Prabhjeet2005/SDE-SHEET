/*
Power Distribution Network in Electrovia
Problem Description
In the growing city of Electrovia, the power distribution network is designed as a balanced
tree, with a central power plant serving as the root. The cities are connected through power
lines, and each power line has an energy transmission cost that depends on its maintenance
and power loss over distance.
Objective
As the city's energy manager, you need to:
1. Monitor the transmission costs between different cities
2. Adjust them as necessary due to maintenance or upgrades
Functionality Requirements
1. Transmission Cost Query:
Calculate the total transmission cost between any two cities.
2. Cost Update Query:
Modify the transmission cost for any specific power line connecting two cities.
Input Format
Network Configuration
●
●
First line contains 3 integers:
○
N (number of cities)
○
R (root city representing the power plant)
○
M (which equals N-1)
The next N-1 lines each contain three integers U, V, W, where:
○
U and V are two connected cities
○
W is the transmission cost along the power line
Queries
●
●
An integer Q indicating the number of queries
Each of the next Q lines describes a query, either:
○
1 A B 0 to calculate the transmission cost between cities A and B
○
2 U V W to update the transmission cost between cities U and V to W
Output Format
Return the sum of results of all transmission cost queries (type 1 queries) between the
specified cities

INPUT FORMAT
5 1 4
1 2 10
1 3 20
2 4 30
2 5 40
3
1 4 5 0
2 2 5 50
1 3 5 0

OUTPUT: 
150
*/

#include <iostream>
#include <vector>
using namespace std;

int n = 5;
vector<vector<pair<int, int>>>adj(n+1); // Tree so n-1 edges

int dfs(int curr,int parent,int dest,int curr_sum){
  if(curr == dest){
    return curr_sum;
  }

  for(auto &neighbor:adj[curr]){
    int node = neighbor.first;
    int weight = neighbor.second;

    if(node != parent){
      int path_sum = dfs(node,curr,dest,curr_sum+weight);
      if(path_sum != -1)return path_sum;
    }
  }
  return -1; // DEAD END
}

int min_cost(vector<vector<int>> &edges, vector<vector<int>> &queries)
{

  for(auto &edge:edges){
    int u = edge[0],v=edge[1],w=edge[2];
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  long long total_sum = 0;

  for(auto &query:queries){
    int type = query[0];
    if(type==1){
      // Calculate transmission cost b/w a and b
      int a=query[1],b=query[2];
      int sum = dfs(a,-1,b,0);
      total_sum += sum;
    }else{
      // Update Transmission cost b/w u and v to w
      int u=query[1],v=query[2],w=query[3];
      for(auto &element: adj[u]){
          int node = element.first;
          int weight = element.second;
          if(node == v)element.second = w;  
      }
      for (auto &element : adj[v])
      {
        int node = element.first;
        int weight = element.second;
        if (node == u)
          element.second = w;
      }
    }
  }

  return total_sum;

}

int main()
{
  vector<vector<int>> edges = {{1, 2, 10}, {1, 3, 20}, {2, 4, 30}, {2, 5, 40}};
  vector<vector<int>> queries = {{1, 4, 5, 0}, {2, 2, 5, 50}, {1, 3, 5, 0}};
  cout << min_cost(edges, queries) << "\n";
}
