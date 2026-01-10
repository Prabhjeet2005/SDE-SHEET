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
    ListNode* reverseLL(ListNode*& node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }
        ListNode* currNode = node;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = node->next;

        while (currNode != nullptr) {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            if (nextNode != nullptr)
                nextNode = nextNode->next;
        }

        return prevNode;
    }

public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* firstListEnd = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            firstListEnd = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (firstListEnd != nullptr)
            firstListEnd->next = nullptr;

        ListNode* firstHead = head;
        ListNode* secondHead = reverseLL(slow);
        while (secondHead != nullptr) {

            ListNode* firstHeadNext = firstHead->next;
            ListNode* secondHeadNext = secondHead->next;
            firstHead->next = secondHead;
            if (firstHeadNext == nullptr)
                break;
            secondHead->next = firstHeadNext;
            secondHead = secondHeadNext;
            firstHead = firstHeadNext;
        }
    }
};