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
        if (!head || !head->next)
            return head;
        ListNode* currNode = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = head->next;

        while (currNode != nullptr) {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            if (nextNode)
                nextNode = nextNode->next;
        }
        return prevNode;
    }

    void printLL(ListNode* head){
        ListNode* curr = head;
        while(curr){
            cout<<curr->val<<" -> ";curr=curr->next;
        }
        cout<<"\n";
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head)
            return false;
        if (!head->next)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* middle = slow;
        ListNode* reversedMidHead = reverseLL(slow);

        ListNode* first = head;
        ListNode* second = reversedMidHead;
        while (first != slow && second != nullptr) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};