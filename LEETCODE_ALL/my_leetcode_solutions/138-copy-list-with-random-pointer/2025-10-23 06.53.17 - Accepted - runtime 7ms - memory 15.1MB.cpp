/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* originalNode = head;
        while (originalNode != nullptr) {
            Node* originalNodeNext = originalNode->next;
            originalNode->next = new Node(originalNode->val);
            originalNode = originalNode->next;
            originalNode->next = originalNodeNext;
            originalNode = originalNode->next;
        }

        originalNode = head;
        while (originalNode != nullptr) {
            if (originalNode->random != nullptr) {
                originalNode->next->random = originalNode->random->next;
            }
            originalNode = originalNode->next->next;
        }

        Node* newHead = new Node(-1);
        originalNode = head;
        Node* newCurr = newHead;

        while (originalNode != nullptr) {
            Node* originalNodeNext = originalNode->next;
            originalNode->next = originalNode->next->next;
            newCurr->next = originalNodeNext;
            newCurr = newCurr->next;
            originalNode = originalNode->next;
        }

        // Node* curr = newHead;
        // while(curr!=nullptr){
        //     cout<<curr->val<<" ";
        //     curr = curr->next;
        // }

        return newHead->next;
    }
};