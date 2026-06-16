#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode
{
  vector<TrieNode *> children; // 26 sized Because 26 characters
  bool end_of_word;
  TrieNode()
  {
    end_of_word = false;
    children.resize(26, nullptr);
  }
};

class Trie
{
  TrieNode *root = new TrieNode();

public:
  void insert_word(string str)
  {

    TrieNode *curr = root;
    for (auto &ch : str)
    {
      int index = ch - 'a';
      if (curr->children[index] == nullptr)
      { // Not Exists
        curr->children[index] = new TrieNode();
      }
      curr = curr->children[index];
    }
    curr->end_of_word = true;
  }

  // Exact Search
  bool search_word(string word)
  {
    TrieNode *curr = root;
    for (auto ch : word)
    {
      int idx = ch - 'a';

      // If Not Present
      if (!curr->children[idx])
      {
        return false;
      }
      curr = curr->children[idx];
    }
    return curr->end_of_word;
  }

  // Prefix Search
  bool start_with(string word)
  {
    TrieNode *curr = root;
    for (auto &ch : word)
    {
      int idx = ch - 'a';
      if (!curr->children[idx])
      {
        return false;
      }
      curr = curr->children[idx];
    }
    // Return True Regardless
    return true;
  }

  void delete_word(string word)
  {
    TrieNode *curr = root;
    for (auto &ch : word)
    {
      int idx = ch - 'a';
      if (!curr->children[idx])
      {
        return;
      }
      curr = curr->children[idx];
    }
    curr->end_of_word = false;
  }
};

int main()
{
  cout << "\n";
  Trie *dictionary = new Trie();
  dictionary->insert_word("apple");
  cout << "StartsWith 'app': "<<dictionary->search_word("apple")<<endl;     // Returns 1 (True)
  cout << "StartsWith 'app': "<<dictionary->search_word("app")<<endl;       // Returns 0 (False - just a prefix)
  cout << "StartsWith 'app': " << dictionary->start_with("app") << endl; // Returns 1 (True)
  
  dictionary->insert_word("app");
  cout << "Search 'app' after insert: " << dictionary->search_word("app") << endl; // Returns 1 (True)
  dictionary->delete_word("apple");
  cout << "Search 'app': "<<dictionary->search_word("app")<<endl;       // Returns 0 (False - just a prefix)

  cout << "\n";
}