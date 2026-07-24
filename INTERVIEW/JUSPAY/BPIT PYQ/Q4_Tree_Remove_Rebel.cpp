/*
The Kingdom's Rebellion
Problem Statement:
In the Kingdom of Arborvale, there is a hierarchical system of nobles arranged in a tree-like
structure. The kingdom has n nobles, each assigned a unique number from 1 to n.
At the top of the hierarchy is the King, who is considered the root of the kingdom's structure.
Each noble has a parent, except the King, who has no parent.
The nobles have ancestral respect rules:

Respects: A noble respects its ancestors if it is loyal to the King's rule.
Rebels: Some nobles, however, do not respect their ancestors and openly defy them.
Given the tension in the kingdom, you decide to remove rebellious nobles one by one to
restore peace.
Removal Process:
1. Select a non-root noble that is rebellious (does not respect its parent) and has no
children that respect it.
2. If there are multiple such nobles, select the one with the smallest index.
3. When a rebellious noble is removed, all its children are immediately reassigned to its
parent.
4. Continue until no more nobles satisfy the removal condition.
Your task is to determine the order in which rebellious nobles will be removed.

Input Format:
First line contains integer n (1 <= n <= 100)
Next n lines contain two integers:

p_i → parent of node i
r_i → whether node i respects parent
Where:
p_i = -1 means node i is the root
r_i = 0 means node respects parent
r_i = 1 means node does not respect parent
It is guaranteed that the given parents form a valid tree.
Output Format:
Print indices of nobles removed in order.
If no such node exists, print -1.
Sample Input:
6
-1 0
1 1
1 1
3 1
3 0
3 0
Sample Output:
2 4
*/

#include<iostream>
#include <vector> 
using namespace std;

void solution(vector<vector<int>>&arr){
  int n = arr.size();
  vector<vector<int>>adj(n+1);
  vector<int>res(n+1);

  for(int i=1; i<=n; i++){
    int parent = arr[i-1][0];
    int rebel = arr[i-1][1];
    
    res[i] = rebel;
    
    if(parent != -1){
      adj[parent].push_back(i);
    }
  }

  bool found = false;
  for(int i=1; i<= n; i++){
    bool all_rebel = true;
    for(int child_idx: adj[i]){
      if(res[child_idx]==0){
        all_rebel = false;
        break;
      }
      found = true; // FIX: Update Found
    }
    // FIX: Check whether parent is Rebel as well
    if(res[i] == 1 && all_rebel)cout<<i<<" "; 
  }

  if(!found)cout<<"-1";
}

int main()
{
  // {parent,rebel}
  vector<vector<int>> arr = {{-1, 0}, {1, 1}, {1, 1}, {3, 1}, {3, 0}, {3, 0}};
  cout<<"\n";
  solution(arr);
  cout<<"\n";
}