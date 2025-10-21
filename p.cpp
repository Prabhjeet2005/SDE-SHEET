
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Node
{
public:
  T data;
  Node<T> *next;
  Node(T data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

class Solution
{
  Node<int> *createLL(vector<int> &arr)
  {
    if (arr.empty())
    {
      return nullptr;
    }
    Node<int> *head = new Node<int>(arr[0]);
    Node<int> *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
      temp->next = new Node<int>(arr[i]);
      temp = temp->next;
    }
    return head;
  }
  void printLL(Node<int> *&head)
  {
    if (head == nullptr)
    {
      return;
    }
    if (head->next == nullptr)
    {
      cout << head->data << ",";
      return;
    }
    Node<int> *temp = head;
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }
  // N -> N -> N -> N -> N
  Node<int> *reverseLLRecursive(Node<int> *&head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    Node<int> *reversedHead = reverseLLRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return reversedHead;
  }

public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node<int> *head = createLL(arr);
    head = reverseLLRecursive(head);
    printLL(head);
  }
};

int main()
{
  Solution sol = Solution();
  cout << "\n";
  sol.solution();
  cout << "\n";
}
