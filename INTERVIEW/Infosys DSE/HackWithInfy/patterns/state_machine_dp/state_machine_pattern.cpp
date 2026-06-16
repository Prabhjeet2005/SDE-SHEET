/*
From an array you can either pick or not pick the elements
BUT if you pick you have to skip the next day
Find max sum

*/



// Button Light Up are the states
#include <vector>
#include <algorithm>
using namespace std;

int stateMachineDP(vector<int> &arr)
{
  if (arr.empty())
    return 0;

  // The Notebook: Track the maximum score for each state
  long long prev_rest = 0;   // Max score if we skipped the previous item
  long long prev_action = 0; // Max score if we picked the previous item

  for (int i = 0; i < arr.size(); i++)
  {
    int current_val = arr[i];

    // 1. Calculate the new REST state:
    // If I rest today, I take the absolute best outcome from yesterday (whether I rested or acted).
    long long current_rest = max(prev_rest, prev_action);

    // 2. Calculate the new ACTION state:
    // If I act today, I MUST have rested yesterday. So I take yesterday's rest score + today's value.
    long long current_action = prev_rest + current_val;

    // 3. Time moves forward. Today's states become tomorrow's previous states.
    prev_rest = current_rest;
    prev_action = current_action;
  }

  // The game is over. Return the best possible timeline.
  return max(prev_rest, prev_action);
}