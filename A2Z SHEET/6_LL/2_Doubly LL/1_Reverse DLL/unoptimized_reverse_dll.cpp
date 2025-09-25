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
    Node<int> *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
      temp->next = new Node<int>(arr[i]);
      temp = temp->next;
    }
    return head;
  }

  Node<int> *reverseDLL(Node<int> *&head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    Node<int> *temp = head;
    stack<int> stack;
    while (temp != nullptr)
    {
      stack.push(temp->data);
      temp = temp->next;
    }

    temp = head;
    while (!stack.empty())
    {
      temp->data = stack.top();
      stack.pop();
      temp = temp->next;
    }
    return head;
  }

  void printDLL(Node<int> *&head)
  {
    Node<int> *temp = head;
    cout << "\n";
    while (temp != nullptr)
    {
      cout << temp->data << ", ";
      temp = temp->next;
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