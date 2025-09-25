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

  int findLengthLL(Node<int> *&head)
  {
    if (head == nullptr)
    {
      return 0;
    }
    if (head->next == nullptr)
    {
      return 1;
    }

    Node<int> *temp = head;
    int counter = 0;
    while (temp != nullptr)
    {
      counter++;
      temp = temp->next;
    }
    return counter;
  }

  int findMiddle(Node<int> *&head)
  {
    int lengthLL = findLengthLL(head);
    if (lengthLL == 0)
    {
      return -1;
    }
    if (lengthLL == 1)
    {
      return head->data;
    }
    Node<int> *temp = head;
    if (lengthLL % 2 != 0)
    {
      int target = lengthLL / 2;
      int counter = -1; // Doing 0-based Indexing
      while (temp != nullptr)
      {
        counter++;
        if (counter == target)
        {
          return temp->data;
        }
        temp = temp->next;
      }
    }
    else
    {
      int target = lengthLL / 2;
      int counter = -1;
      while (temp != nullptr)
      {
        counter++;
        if (counter == target)
        {
          return temp->data;
        }
        temp = temp->next;
      }
    }
    return -1;
  }

public:
  void solution()
  {
    vector<int> arr = {1, 4,70, 99, 6, 88};
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