/*
Give max XOR of any 2 elements in array

Input:
vector<int> arr = {3, 10, 5, 25, 2, 8};
x = 5

Output:


*/

#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
  vector<TrieNode *> children; // 0 or 1

  TrieNode()
  {
    children.resize(2, nullptr);
  }
};

class BitwiseTrie
{
  TrieNode *root = new TrieNode();

public:
  void insert(int num)
  {
    TrieNode *curr = root;

    // Most Significant to Least Significant Bit
    for (int i = 31; i >= 0; i--)
    {
      int bit = (num >> i) & 1;

      if (!curr->children[bit])
      {
        curr->children[bit] = new TrieNode();
      }
      curr = curr->children[bit];
    }
  }

  int get_max_xor(int num)
  {
    TrieNode *curr = root;
    int max_xor = 0;

    for (int i = 31; i >= 0; i--)
    {
      int bit = (num >> i) & 1;

      // Opposite Bit for MAX Xor
      int opposite_bit = 1 - bit;

      if (curr->children[opposite_bit])
      {
        // Means Max Xor which means at this bit it will give Max Xor i.e 1
        max_xor = max_xor | (1 << i);

        curr = curr->children[opposite_bit];
      }
      else
      {
        // Move to bit
        curr = curr->children[bit];
      }
    }
    return max_xor;
  }
};

int main()
{
  cout << "\n";
  vector<int> arr = {3, 10, 5, 25, 2, 8};
  BitwiseTrie *trie = new BitwiseTrie();

  for (int &element : arr)
  {
    trie->insert(element);
  }

  int num = 5;
  cout << "Max Xor between " << num << " is: " << trie->get_max_xor(num);

  cout << "\n";
}