#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* --------------------------------------------------
                    HUFFMAN
 -------------------------------------------------- */

struct Node
{
  char ch;
  int freq;
  Node *left, *right;
  Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

// Comparator for Min-Heap
struct compare
{
  bool operator()(Node *l, Node *r)
  {
    return l->freq > r->freq;
  }
};

// Print Huffman Codes
void printCodes(Node *root, string str)
{
  if (!root)
    return;
  if (root->ch != '$') // If leaf node
    cout << root->ch << ": " << str << "\n";
  printCodes(root->left, str + "0");
  printCodes(root->right, str + "1");
}

void HuffmanCodes(vector<char> &data, vector<int> &freq)
{
  priority_queue<Node *, vector<Node *>, compare> minHeap;

  for (int i = 0; i < data.size(); ++i)
    minHeap.push(new Node(data[i], freq[i]));

  while (minHeap.size() != 1)
  {
    Node *left = minHeap.top();
    minHeap.pop();
    Node *right = minHeap.top();
    minHeap.pop();

    Node *top = new Node('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    minHeap.push(top);
  }
  printCodes(minHeap.top(), "");
}

int main()
{
  vector<char> arr = {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<int> freq = {5, 9, 12, 13, 16, 45};
  HuffmanCodes(arr, freq);
  return 0;
}