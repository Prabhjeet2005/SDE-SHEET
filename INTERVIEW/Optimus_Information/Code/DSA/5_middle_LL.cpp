#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    next = nullptr;
  }
};

int find_middle_LL(Node *head)
{
  if (!head)
    return -1;
  if (!head->next)
    return head->data;

  Node *slow = head;
  Node *fast = head;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->data;
}

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  cout << find_middle_LL(head) << "\n";
}