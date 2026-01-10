/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int calculateLengthLL(ListNode* head){
        ListNode* curr = head;
        if(!head)return 0;
        if(!head->next)return 1;
        int lengthLL = 0;
        while(curr!=nullptr){
            lengthLL++;
            curr = curr->next;
        }
        return lengthLL;
    }
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int length1 = 0, length2 = 0;
        length1 = calculateLengthLL(headA);
        length2 = calculateLengthLL(headB);

        int difference = abs(length1 - length2);

        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        while (length1 > length2) {
            curr1 = curr1->next;
            length1--;
        }
        while (length1 < length2) {
            curr2 = curr2->next;
            length2--;
        }

        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1 == curr2)
                return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return nullptr;
    }
};