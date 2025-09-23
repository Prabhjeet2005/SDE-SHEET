#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class Node
{
public:
  T data;
  Node<T> *next;
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
  }
};

class Solution
{
  Node<int> *convertArrToLL(vector<int> &arr)
  {
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
    Node<int> *temp = head;
    while (head != nullptr)
    {
      cout << head->data << ", ";
      head = head->next;
    }
  }
  bool findElementLL(Node<int> *&head, int value)
  {
    Node<int> *temp = head;
    while (temp != nullptr)
    {
      if (temp->data == value)
      {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  Node<int> *deleteBegLL(Node<int> *&head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }
    if (head->next == nullptr)
    {
      delete head;
      return nullptr;
    }
    Node<int> *temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  Node<int> *deleteEndLL(Node<int> *&head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }
    if (head->next == nullptr)
    {
      delete head;
      return nullptr;
    }
    Node<int> *temp = head;
    while (temp->next->next != nullptr)
    {
      temp = temp->next;
    }
    Node<int> *nextElement = temp->next->next;
    delete temp->next;
    temp->next = nextElement;
    return head;
  }

  Node<int> *deletePositionLL(Node<int> *&head, int position)
  {
    /*
    If head nullptr return nullptr
    if position == 1 delete head & return nullptr

    */

    if (head == nullptr)
    {
      return nullptr;
    }
    if (position == 1)
    {
      Node<int> *temp = head->next;
      delete head;
      return temp;
    }
    Node<int> *prevElement = head;
    Node<int> *currElement = head->next;
    int count = 1;

    while (currElement != nullptr)
    {
      count++;
      if (count == position)
      {
        prevElement->next = currElement->next;
        delete currElement;
        break;
      }
      prevElement = currElement;
      currElement = currElement->next;
    }

    return head;
  }

  Node<int> *deleteValLL(Node<int> *&head, int value)
  {
    if (head == nullptr)
      return nullptr;

    if (head->data == value)
    {
      Node<int> *temp = head->next;
      delete head;
      return temp;
    }

    Node<int> *prev = head;
    Node<int> *curr = head->next;

    while (curr != nullptr)
    {
      if (curr->data == value)
      {
        prev->next = curr->next;
        delete curr;
        break;
      }
      prev = curr;
      curr = curr->next;
    }
    return head;
  }

  Node<int> *insertAtBeg(Node<int> *&head, int data)
  {
    if (head == nullptr)
    {
      return new Node<int>(data);
    }
    Node<int> *newHead = new Node<int>(data);
    newHead->next = head;
    head = newHead;
    return head;
  }

  Node<int> *insertAtEnd(Node<int> *&head, int data)
  {
    if (head == nullptr)
    {
      return new Node<int>(data);
    }
    Node<int> *curr = head;
    while (curr->next != nullptr)
    {
      curr = curr->next;
    }
    Node<int> *newNode = new Node<int>(data);
    curr->next = newNode;
    return head;
  }

  Node<int> *insertAtPosition(Node<int> *&head, int data, int position)
  {
    if (head == nullptr)
    {
      return new Node<int>(data);
    }
    if (position == 1)
    {
      Node<int> *newNode = new Node<int>(data);
      newNode->next = head;
      head = newNode;
      return head;
    }
    int counter = 1;
    Node<int> *prev = head;
    Node<int> *curr = head->next;

    while (curr != nullptr)
    {
      counter++;
      if (counter == position)
      {
        Node<int> *newNode = new Node<int>(data);
        prev->next = newNode;
        newNode->next = curr;
        break;
      }
      prev = curr;
      curr = curr->next;
    }
    if (counter == position - 1)
    { // Insert at end
      Node<int> *newNode = new Node<int>(data);
      prev->next = newNode;
    }
    return head;
  }

  Node<int> *insertAtValue(Node<int> *&head, int data, int targetValue)
  {
    if (head == nullptr)
    {
      return new Node<int>(data);
    }
    if (head->data == targetValue)
    {
      Node<int> *newNode = new Node<int>(data);
      newNode->next = head;
      head = newNode;
      return head;
    }
    Node<int> *prev = head;
    Node<int> *curr = head->next;
    while (curr != nullptr)
    {
      if (curr->data == targetValue)
      {
        Node<int> *newNode = new Node<int>(data);
        prev->next = newNode;
        newNode->next = curr;
        break;
      }
      prev = curr;
      curr = curr->next;
    }
    return head;
  }

public:
  void
  solution()
  {
    vector<int> arr = {4, 6, 3, 2, 7};
    Node<int> *head = convertArrToLL(arr);
    bool found = findElementLL(head, 2);
    cout << "Found In LL: " << found << "\n";
    // head = deleteBegLL(head);
    // head = deleteEndLL(head);
    // head = deletePositionLL(head, 1); // Give Position eg: 1st position
    // head = deleteValLL(head, 3);
    // head = insertAtBeg(head, 99);
    // head = insertAtEnd(head, 99);
    // head = insertAtPosition(head, 99, 3); // Edge Case Of Insertion At Tail
    head = insertAtValue(head, 99, 6);
    printLL(head);
  }
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}