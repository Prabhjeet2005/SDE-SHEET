#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  vector<vector<int>> adj_list;
  vector<long long> subtree_ans; // Ans For Every Node
  vector<int> values;            // Each Node Value
public:
  void dfs(int curr_node, int parent_node)
  {
    subtree_ans[curr_node] = values[curr_node];
    
    for(auto &child:adj_list[curr_node]){
      if(child != parent_node){ // Avoid Parent Infinite Loop
        dfs(child,curr_node);

        subtree_ans[curr_node] += subtree_ans[child];

      }
    }
  }
};

int main()
{
  Solution sol = Solution();
  cout << "\n";
  cout << "\n";
}