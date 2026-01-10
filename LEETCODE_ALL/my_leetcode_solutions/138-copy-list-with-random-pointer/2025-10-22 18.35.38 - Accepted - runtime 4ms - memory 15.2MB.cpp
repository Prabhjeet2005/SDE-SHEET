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
        if(head==nullptr)return head;
        Node* currNode = head;
        unordered_map<Node*,Node*> originalNewMap;

        while(currNode != nullptr){
            originalNewMap[currNode] = new Node(currNode->val);
            currNode = currNode->next;
        }

        currNode = head;
        Node* newHead = new Node(-1);
        Node* currNew = newHead;
        while(currNode != nullptr){
            currNew->next = originalNewMap[currNode];
            currNew = currNew->next;
            currNew -> val = currNode->val;
            if(currNode->random == nullptr)currNew->random = nullptr;
            else currNew -> random = originalNewMap[currNode->random];
            currNode = currNode->next;
        }

        return newHead->next;
    }
};