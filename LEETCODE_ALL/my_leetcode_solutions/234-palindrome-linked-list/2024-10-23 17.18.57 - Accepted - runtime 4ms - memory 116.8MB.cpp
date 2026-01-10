/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void rev(ListNode *&head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *fwd = NULL;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    head = prev;
}

ListNode *mid(ListNode *&head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast != NULL)
        slow = slow->next;

    return slow;
}

bool isPalindrome(ListNode *&head)
{
    if (head == NULL || head->next == NULL)
        return 1;
    int len = 0;
    ListNode *temp = head;
    ListNode *middle = mid(head);
    rev(middle);
    cout << endl;
    ListNode *f = head;
    ListNode *s = middle;
    while (s != NULL)
    {
        if (s->val == f->val)
        {
            s = s->next;
            f = f->next;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
};