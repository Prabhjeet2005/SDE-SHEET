/*
Smart City Traffic Toll System
Background
In a smart city, there are an infinite number of traffic control hubs numbered with positive
integers starting from 1.
Each hub is connected by smart roads in a unique tree-like structure:
1. There is a direct, bidirectional road between hub i and 2i.
2. Another direct, bidirectional road exists between hub i and 2i + 1.
Given this structure, there is always a unique shortest path between any two traffic control
hubs.
Initially, passing through any road is toll-free.
However, to optimize traffic flow and manage congestion, the city traffic authority
occasionally imposes toll fees on certain roads along specific paths.
The traffic authority will introduce a series of changes:
1. Toll Fee Update:
An update described by integers x, y, and t imposes a toll of t units on all roads
along the shortest path from hub x to hub y.
2. Travel Cost Calculation:
A commuter travels from hub x to hub y using the shortest path, and you need to
calculate the total toll fees they incur.
Input
First line contains an integer q (1 <= q <= 100000), representing the number of
events.
Next q lines each contain 4 integers:
If first integer is 1:
1 x y t
impose toll t on all roads from hub x to hub y.
If first integer is 2:
2 x y 0
calculate total cost from hub x to hub y.
Output
For each travel query (2 x y 0), compute the trip cost and add it to a running sum.
Print the final accumulated sum.
Sample Input:
3
1 1 2 4
1 2 4 2
2 1 4 0
Sample Output:
6
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long solve(int x, int y, unordered_map<int, int> &node_toll)
{
  long long cost = 0;
  while (x != y)
  {
    int maxi = max(x, y);
    cost += node_toll[maxi];
    if (x > y)
      x /= 2;
    else
      y /= 2;
  }
  return cost;
}

long long get_cost(vector<vector<int>> &queries)
{
  unordered_map<int, int> node_toll;
  long long cost = 0;
  for (auto &query : queries)
  {
    int type = query[0], x = query[1], y = query[2];
    if (type == 1)
    {
      // Update toll
      int toll = query[3];
      // PARENT : node/2
      while(x!= y){
        if(x>y){
          node_toll[x]+=toll;
          x/=2;
        }else{ 
          node_toll[y]+=toll;
          y/=2;
        }
      }
    }
    else
    {
      // Calculate cost
      cost += solve(x, y, node_toll);
    }
  }
  return cost;
}

int main()
{
  vector<vector<int>> queries = {{1, 1, 2, 4}, {1, 2, 4, 2}, {2, 1, 4, 0}};

  cout << get_cost(queries) << "\n";
}