#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>

class Node
{
public:
  T data;
  Node<T> *next;
  Node<T> *prev;
  Node(T data)
  {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }
};

class Solution
{
  Node<int> *convertArr2DLL(vector<int> &arr)
  {
    if (arr.size() == 0)
    {
      return nullptr;
    }
    Node<int> *head = new Node<int>(arr[0]);
    Node<int> *currNode = head;

    for (int i = 1; i < arr.size(); i++)
    {
      currNode->next = new Node<int>(arr[i]);
      currNode = currNode->next;
    }
    return head;
  }

  Node<int> *reverseDLL(Node<int> *&head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    Node<int> *currNode = head;
    Node<int> *prevNode = nullptr;

    while (currNode != nullptr)
    {
      currNode->prev = currNode->next;
      currNode->next = prevNode;
      prevNode = currNode;
      currNode = currNode->prev;
    }
    return prevNode;
  }

  void printDLL(Node<int> *&head)
  {
    Node<int> *currNode = head;
    cout << "\n";
    while (currNode != nullptr)
    {
      cout << currNode->data << ", ";
      currNode = currNode->next;
    }
    cout << "\n";
  }

public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 7, 9, 10};
    Node<int> *head = convertArr2DLL(arr);
    head = reverseDLL(head);
    printDLL(head);
  }
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}