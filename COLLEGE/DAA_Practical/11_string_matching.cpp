#include <iostream>
#include <string>
using namespace std;

/* --------------------------------------------------
                    STRING MATCHING
 -------------------------------------------------- */

void search(string pat, string txt)
{
  int M = pat.length();
  int N = txt.length();

  // Loop through the text
  for (int i = 0; i <= N - M; i++)
  {
    int j;
    // For current index i, check for pattern match
    for (j = 0; j < M; j++)
    {
      if (txt[i + j] != pat[j])
        break;
    }

    // If loop finished, pattern found
    if (j == M)
      cout << "Pattern found at index " << i << endl;
  }
}

int main()
{
  string txt = "AABAACAADAABAABA";
  string pat = "AABA";
  search(pat, txt);
  return 0;
}