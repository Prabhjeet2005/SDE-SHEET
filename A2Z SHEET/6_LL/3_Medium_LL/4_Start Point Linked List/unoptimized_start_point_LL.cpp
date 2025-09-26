#include <iostream>
#include <vector>
#include <unordered_set>

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
  Node<int> *convertArrToLL(vector<int> &arr)
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
  void printLL(Node<int> *&head)
  {
    if (head == nullptr)
    {
      return;
    }

    Node<int> *temp = head;
    while (temp != nullptr)
    {
      cout << temp->data << ", ";
      temp = temp->next;
    }
    cout << "\n";
  }

  Node<int> *findStartLL(Node<int> *&head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    unordered_set<Node<int> *> set;
    Node<int> *curr = head;
    while (curr != nullptr)
    {
      if (set.find(curr) != set.end())
      {
        return curr;
      }
      set.insert(curr);
      curr = curr->next;
    }
    return nullptr;
  }

public:
  void solution()
  {
    vector<int> arr = {1, 4, 2, 6, 88};
    Node<int> *head = convertArrToLL(arr);
    head->next->next->next->next->next = head->next->next;

    Node<int> *start = findStartLL(head);
    cout << "Start Of LL Loop: " << start->data;
  }
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}