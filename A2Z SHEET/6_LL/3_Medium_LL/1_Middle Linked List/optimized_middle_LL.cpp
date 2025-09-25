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

  int findMiddle(Node<int> *&head)
  {
    if (head == nullptr)
    {
      return 0;
    }
    if (head->next == nullptr)
    {
      return head->data;
    }

    Node<int> *slow = head;
    Node<int> *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow->data;
  }

public:
  void solution()
  {
    vector<int> arr = {1, 4, 70, 99, 6, 88};
    Node<int> *head = convertArrToLL(arr);
    int middle = findMiddle(head);
    cout << "Middle: " << middle;
  }
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}