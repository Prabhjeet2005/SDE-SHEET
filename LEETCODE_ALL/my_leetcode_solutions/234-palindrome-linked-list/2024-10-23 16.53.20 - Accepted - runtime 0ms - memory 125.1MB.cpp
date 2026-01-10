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
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    int *arr = new int[cnt];
    temp = head;
    int k = 0;
    while (temp != NULL)
    {
        arr[k++] = temp->val;
        temp = temp->next;
    }
    int i = 0, j = cnt - 1;
    while (i < j)
    {
        if (arr[i] != arr[j])
        {
            delete[] arr;
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }
    delete[] arr;
    return 1;
    }
};