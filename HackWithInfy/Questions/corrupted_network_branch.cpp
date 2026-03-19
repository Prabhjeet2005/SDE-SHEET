/*
### ⚔️ Blind Story-Stripping Challenge 12

You have mastered the basic Subtree Sum. Now, let's look at how HackWithInfy twists this exact concept to make it a "Medium/Hard" problem.

 **Problem: The Corrupted Network Nodes**

 You are debugging the Infosys internal server network, which consists of N servers connected by N-1 cables (rooted at server 0).

 A recent cyber-attack corrupted some of the servers. You are given an integer array `status` of size N, where:
 * `status[i] = 1` means the server is **Corrupted**.
 * `status[i] = 0` means the server is **Safe**.

 The IT department needs to disconnect entire branches of the network to quarantine the corruption. To do this, they need to know how many corrupted servers are in each branch.

 You receive Q queries. Each query gives you a server ID, U. For each query, you must return the **total number of Corrupted servers** in the entire subtree of Server U.

 **Constraints:**
 1 <= N <= 10^5
 1 <= Q <= 10^5
 `status[i]` is either 0 or 1.

 ---

 INPUT:
 6
4
0
1
1
0
1
0
0 1
0 2
1 3
1 4
2 5
0
1
2
5

OUTPUT:
3
2
1
0

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  vector<vector<int>> adj_list;
  vector<int>subtree;
  vector<int>values;

public:
  void solution(int N,int Q,vector<vector<int>> &edges, vector<int> &status, vector<int> &queries)
  {
    adj_list.resize(N+1);
    subtree.resize(N+1,0);
    values = status;

    for(auto &edge:edges){
      int u = edge[0], v = edge[1];
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }

    dfs(0,-1);

    vector<int>result(Q);
    for(int i=0; i<Q; i++){
      int ans =  subtree[queries[i]];
      result[i] = ans;
    }
    for(auto &element:result){
      cout<< element<<" ";
    }
  }
  private:
  void dfs(int curr_node,int parent_node){
    subtree[curr_node] = values[curr_node];
    for(auto &child: adj_list[curr_node]){
      if(child != parent_node){
        dfs(child,curr_node);
        subtree[curr_node] += subtree[child]; // ACTUAL MATHS
      }
    }
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  int N, Q;
  vector<vector<int>> edges;
  vector<int> status;
  vector<int> queries;
  cin >> N >> Q;
  for (int i = 0; i < N; i++)
  {
    int s;
    cin >> s;
    status.push_back(s);
  }
  for (int i = 0; i < N - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  for (int i = 0; i < Q; i++)
  {
    int q;
    cin >> q;
    queries.push_back(q);
  }
  sol.solution(N,Q,edges, status, queries);
  cout << endl;
}