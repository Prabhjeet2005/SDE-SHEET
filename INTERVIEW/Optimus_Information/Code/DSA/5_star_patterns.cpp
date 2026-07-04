#include <iostream>
using namespace std;

void print_pattern_1()
{
  int n = 3;
  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i; j >= 1; j--)
    {
      cout << " ";
    }
    for (int j = 1; j <= i; j++)
    {
      cout << "* ";
    }
    cout << "\n";
  }
}

void print_pattern_2()
{
  int n = 4;
  int j = 2;
  for (int i = 1; i <= n; i++)
  {
    if (i == 1)
      cout << "*";
    else
    {
      for (int k = 0; k < j; k++)
      {
        cout << "*";
      }
      j += 2;
    }
    cout << "\n";
  }
}

int main()
{

  //   *
  //  * *
  // * * *

  cout << "\n";
  print_pattern_1();
  cout << "\n";
  cout << "\n";

  // *
  // **
  // ****
  // ******
  print_pattern_2();
  cout << "\n";
}