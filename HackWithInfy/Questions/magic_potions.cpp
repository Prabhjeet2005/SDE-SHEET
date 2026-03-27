/*
***
**Problem: The Magic Potions**

 You are a knight exploring a dungeon with N sequential rooms. In each room, there is a potion. You are given an array `potions`, where `potions[i]` is the effect of the i-th potion.
 * Positive numbers heal you (add to your health).
 * Negative numbers poison you (subtract from your health).

 You start the dungeon with **0 health**.
 As you walk from left to right, you can choose to drink the potion or skip it.
 However, if your health ever drops **strictly below 0**, you instantly die.

 Find the maximum number of potions you can drink without dying.

 **Constraints:**
 1 <= N <= 2 \times 10^5
 -10^9 <= potions[i] <= 10^9

**INPUT FORMAT:**
Line 1: N
Line 2: N integers representing `potions`

**Sample Input:**

6
4 -5 3 -2 -1 2


**Sample Output:**

5

*(Explanation: Drink 4 (Health=4). Drink -5? No, health would be -1. Skip it. Drink 3 (Health=7). Drink -2 (Health=5). Drink -1 (Health=4). Drink 2 (Health=6). Total drank = 5 potions... Wait, let's use the Time Travel Greedy strategy!)*

Total potions drank: **5**. (The Greedy strategy perfectly optimizes the choices!).
*/

#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

class Solution
{
public:
  void solution(int n,vector<int>&potions)
  {
    // Can't SORT
    long long health = 0,count = 0;
    // Min Heap (if health -ve remove most poisonous Eg: not -1 but -100 so min heap)
    priority_queue<long long,vector<long long>,greater<long long>>min_heap;


    // Take everything right now if die UNDO biggest mistake
    for(auto &element:potions){
      health += element;
      count++;
      if(element < 0){
        min_heap.push(element);
      }

      if(health < 0 ){
        long long most_poisonous = min_heap.top();
        min_heap.pop();
        health -= most_poisonous; // Add Potion (-) + (-) -> (+)
        count--;

      }
    }

    cout<<"Potions: "<<count;

  }
};

int main()
{
  Solution sol = Solution();
  int n;
  cin>>n;
  vector<int>potions;
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    potions.push_back(a);
  }
  cout << endl;
  sol.solution(n,potions);
  cout << endl;
}