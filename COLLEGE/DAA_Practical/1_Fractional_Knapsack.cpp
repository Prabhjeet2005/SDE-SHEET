#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <unistd.h>
#include <iomanip>

using namespace std;

/* --------------------------------------------------
                    FRACTIONAL KNAPSACK
 -------------------------------------------------- */

struct Items
{
  int value, weight;
};

bool static custom_compare(Items a, Items b)
{
  double ratio1 = (double)a.value / a.weight;
  double ratio2 = (double)b.value / b.weight;

  return ratio1 > ratio2;
}

double fractional_knapsack(vector<Items> &items, int capacity)
{
  sort(items.begin(), items.end(), custom_compare);
  double ans = 0;
  for (int i = 0; i < items.size(); i++)
  {
    usleep(1000);
    if (items[i].weight <= capacity)
    {
      // within limit
      capacity -= items[i].weight;
      ans += items[i].value;
    }
    else
    {
      // exceed limit
      ans += items[i].value * ((double)capacity / items[i].weight); // what percentage
      break;
    }
  }
  return ans;
}

int main()
{
  int capacity = 50;
  vector<Items> items = {{60, 10}, {100, 20}, {120, 30}};
  auto start = chrono::high_resolution_clock::now();
  double ans = fractional_knapsack(items, capacity);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;
  cout << fixed << setprecision(3);
  cout << "Fractional Knapsack: " << ans << "\n";
  cout << duration.count();
}
// OUTPUT
// Fractional Knapsack : 240.000