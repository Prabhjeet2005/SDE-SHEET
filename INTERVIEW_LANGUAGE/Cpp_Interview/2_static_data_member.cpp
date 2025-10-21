#include <iostream>
using namespace std;

class Players
{
  static int count;

public:
  Players()
  {
    count++;
  }
  static int getCount()
  {
    return count;
  }
};

int Players::count = 0;

int main()
{
  Players player1 = Players();
  Players player2 = Players();
  cout << Players::getCount() << "," << player2.getCount() << "," << player1.getCount() << "\n";
}