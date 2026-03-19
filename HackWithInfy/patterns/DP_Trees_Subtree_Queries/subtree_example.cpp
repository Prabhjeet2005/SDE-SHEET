/*
### ⚔️ Blind Story-Stripping Challenge 11

Let's test this directly. This is a highly standard Subtree Query problem, designed exactly like the HackWithInfy ones.

 **Problem: The Intergalactic Supply Chain**

 You are managing a massive interstellar supply chain consisting of N space stations. There are exactly N-1 hyperspace jump routes connecting the stations, ensuring that any station can reach any other station. The entire network is commanded by the Capital Station (Station 0).

 You are given an array `cargo`, where `cargo[i]` represents the exact tons of cargo currently sitting at Station i.

 Because of a massive galactic storm, the Capital Station needs to audit the network. You receive Q queries. Each query provides a station ID, U. For each query, you must return the total tons of cargo in the **entire jurisdiction of Station U** (which includes Station U itself, and every single station that reports up to it—its subtree).

 **Constraints:**
 1 <= N <= 10^5
 1 <= Q <= 10^5
 1 <= cargo[i] <= 10^4
 The network is given as a 2D array of `edges` where `edges[i] = [u, v]`.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  // adj_list + subtree + values
  vector<vector<int>> adj_list;
  vector<int> subtree;
  vector<int> values;

public:
  void solution()
  {
    int N = 5;
    vector<int> cargo = {10, 20, 30, 40, 50};
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    vector<int>queries = {0,1,3};

    // adj_list + subtree + values
    adj_list.resize(N+1);
    subtree.resize(N+1,0);
    values = cargo;

    for(auto edge:edges){
      int u = edge[0], v = edge[1];
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }

    dfs(0,-1);

    for(auto &query:queries){
      cout<<"Query "<<query<<" : "<<subtree[query]<<"\n";
    }
  }
  private:
  void dfs(int curr_node,int parent_node){
    // Subtree = curr_node + subtree of child
    subtree[curr_node] = values[curr_node];
    for(auto &child: adj_list[curr_node]){
      if(child != parent_node){
        dfs(child,curr_node);
        subtree[curr_node] += subtree[child];
      }
    }
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}