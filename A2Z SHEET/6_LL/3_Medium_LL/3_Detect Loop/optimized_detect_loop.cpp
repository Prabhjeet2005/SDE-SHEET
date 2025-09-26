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

  bool detectLoop(Node<int> *&head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return false;
    }
    Node<int> *slow = head;
    Node<int> *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
      if (slow == fast )
      {
        return 1;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return 0;
  }

public:
  void solution()
  {
    vector<int> arr = {1, 4, 2, 6, 88};
    Node<int> *head = convertArrToLL(arr);
    head->next->next = head;
    bool loopPresent = detectLoop(head);
    cout << "Loop Present: " << loopPresent;
  }
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}