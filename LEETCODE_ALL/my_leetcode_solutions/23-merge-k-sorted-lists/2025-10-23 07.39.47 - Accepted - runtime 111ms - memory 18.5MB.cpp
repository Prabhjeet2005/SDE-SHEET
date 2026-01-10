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
    ListNode* merge2Lists(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode(-1);
        ListNode* curr1 = head1;
        ListNode* curr2 = head2;
        ListNode* ans = newHead;
        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                ans->next = curr1;
                curr1 = curr1->next;
            } else {
                ans->next = curr2;
                curr2 = curr2->next;
            }
            ans = ans->next;
        }

        if (curr1) {
            ans->next = curr1;
        } else if (curr2) {
            ans->next = curr2;
        }

        return newHead->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ansHead = new ListNode(-1);
        ListNode* curr = ansHead;
        for (int i = 0; i < lists.size(); i++) {
            if (ansHead == curr && lists[i]) {
                ansHead->next = lists[i];
                curr = nullptr;
                continue;
            }
            ansHead->next = merge2Lists(ansHead->next, lists[i]);
        }
        return ansHead->next;
    }
};