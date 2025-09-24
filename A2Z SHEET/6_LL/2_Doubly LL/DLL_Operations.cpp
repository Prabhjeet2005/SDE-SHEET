#include <iostream>
#include <vector>
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
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class Solution
{
  Node<int> *covertArrToDLL(vector<int> &arr)
  {
    if (arr.size() == 0)
    {
      return nullptr;
    }
    Node<int> *head = new Node<int>(arr[0]);
    if (arr.size() == 1)
    {
      return head;
    }
    Node<int> *prevNode = head;

    for (int i = 1; i < arr.size(); i++)
    {
      Node<int> *newNode = new Node<int>(arr[i]);
      newNode->prev = prevNode;
      prevNode->next = newNode;
      prevNode = newNode;
    }
    return head;
  }

  void printDLL(Node<int> *&head)
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
  Node<int> *insertHead(Node<int> *&head, int element)
  {
    if (head == nullptr)
    {
      return new Node<int>(element);
    }
    Node<int> *newNode = new Node<int>(element);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
  }

  Node<int> *insertEnd(Node<int> *&head, int element)
  {
    if (head == nullptr)
    {
      return new Node<int>(element);
    }
    Node<int> *newNode = new Node<int>(element);
    Node<int> *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
  }
  Node<int> *insertPosition(Node<int> *&head, int position, int element)
  {
    if (head == nullptr)
    {
      Node<int> *newNode = new Node<int>(element);
      return newNode;
    }
    if (position == 1)
    {
      Node<int> *newNode = new Node<int>(element);
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
      return head;
    }
    Node<int> *prevNode = head;
    Node<int> *currNode = head->next;
    int counter = 1;
    while (currNode != nullptr)
    {
      counter++;
      if (counter == position)
      {
        Node<int> *newNode = new Node<int>(element);
        newNode->prev = prevNode;
        newNode->next = currNode;
        prevNode->next = newNode;
        currNode->prev = newNode;
        break;
      }
      prevNode = currNode;
      currNode = currNode->next;
    }
    if (counter == position - 1)
    {
      Node<int> *newNode = new Node<int>(element);
      newNode->prev = prevNode;
      prevNode->next = newNode;
    }

    return head;
  }
  Node<int> *deleteHead(Node<int> *&head) {}
  Node<int> *deleteTail(Node<int> *&head) {}
  Node<int> *deletePosition(Node<int> *&head, int position) {}
  Node<int> *deleteValue(Node<int> *&head, int element) {}

public:
  void
  solution()
  {
    vector<int> arr = {2, 6, 3, 99};
    Node<int> *head = covertArrToDLL(arr);
    // head = insertHead(head,1000);
    // head = insertEnd(head,1000);
    // head = insertPosition(head, 3, 1000);
    head = deleteHead(head);
    head = deleteTail(head);
    head = deletePosition(head);
    head = deleteValue(head);

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