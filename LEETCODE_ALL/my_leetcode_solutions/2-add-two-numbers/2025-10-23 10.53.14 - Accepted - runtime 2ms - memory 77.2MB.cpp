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

    ListNode* reverseLL(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = head->next;

        while (currNode != nullptr) {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            if (nextNode->next)
                nextNode = nextNode->next;
        }
        return prevNode;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* newHead = new ListNode(-1); // Dummy Head
        ListNode* currAns = newHead;
        while (curr1 != nullptr || curr2 != nullptr || carry == 1) {
            int currentDigitInteger = carry, sum = 0;
            if (curr1 && curr2) {
                sum = curr1->val + curr2->val;
                currentDigitInteger = (sum+ carry) % 10;
            } else if (curr1 && !curr2) {
                sum = curr1->val;
                currentDigitInteger = (sum+ carry) % 10;
            } else if (!curr1 && curr2) {
                sum = curr2->val;
                currentDigitInteger = (sum+ carry) % 10;
            }
            ListNode* currDigit = new ListNode(currentDigitInteger);
            currAns->next = currDigit;
            currAns = currAns->next;
            if (curr1)
                curr1 = curr1->next;
            if (curr2)
                curr2 = curr2->next;

            if (sum + carry > 9 )
                carry = 1;
            else
                carry = 0;
        }

        return newHead->next;
    }
};