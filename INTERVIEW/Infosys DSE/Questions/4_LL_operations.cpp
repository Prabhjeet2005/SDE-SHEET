#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int value)
  {
    val = value;
    next = nullptr;
  }
};

class Solution
{
public:
  void solution()
  {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    insert_beg(head, 20);
    insert_end(head, 23);
    get_beg(head);
    get_end(head);
    update(head, 2, 78);
    delete_beg(head);
    delete_end(head);
    delete_value(head, 3);
    print_ll(head);
  }

private:
  void print_ll(ListNode *&head)
  {
    if (!head)
    {
      cout << "Empty LL\n";
      return;
    }
    ListNode *temp = head;
    cout << "Printing LL: ";
    while (temp)
    {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << "\n";
  }

  void insert_beg(ListNode *&head, int value)
  {
    if (!head)
    {
      head = new ListNode(value);
      return;
    }
    ListNode *new_node = new ListNode(value);
    new_node->next = head;
    head = new_node;
  }

  void insert_end(ListNode *&head, int value)
  {
    ListNode *new_node = new ListNode(value);
    if (!head)
    {
      head = new_node;
      return;
    }
    ListNode *temp = head;
    while (temp->next)
    {
      temp = temp->next;
    }
    temp->next = new_node;
  }

  void get_beg(ListNode *head)
  {
    if (!head)
    {
      cout << "Empty\n";
      return;
    }
    cout << "Beginning: " << head->val << endl;
  }

  void get_end(ListNode *head)
  {
    ListNode *temp = head;
    if (!head)
    {
      cout << "Empty\n";
      return;
    }
    while (temp->next)
    {
      temp = temp->next;
    }
    cout << "At End: " << temp->val << "\n";
  }

  void update(ListNode *&head, int prev_value, int new_value)
  {
    if (!head)
    {
      return;
    }

    ListNode *temp = head;
    while (temp)
    {
      if (temp->val == prev_value)
      {
        temp->val = new_value;
        return;
      }
      temp = temp->next;
    }
  }

  void delete_beg(ListNode *&head)
  {
    if (!head)
      return;

    ListNode *temp = head;
    head = head->next;
    delete temp;
  }

  void delete_end(ListNode *&head)
  {
    if (!head)
      return;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr->next)
    {
      prev = curr;
      curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
  }

  void delete_value(ListNode *&head, int value)
  {
    if (!head)
    {
      return;
    }
    if (head->val == value)
    {
      delete_beg(head);
      return;
    }
    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr)
    {
      if (curr->val == value)
      {
        prev->next = curr->next;
        delete curr;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
  }
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}