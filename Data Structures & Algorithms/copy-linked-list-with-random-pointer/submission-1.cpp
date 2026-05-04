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
        if(head == nullptr) return nullptr;
        Node* dummy = head;
        while(dummy != nullptr) {
            Node* copy = new Node(dummy->val);
            copy->next = dummy->next;
            dummy->next = copy;
            dummy = copy->next;
        }
        dummy = head;
        while(dummy != nullptr) {
            if(dummy->random) {
                dummy->next->random = dummy->random->next;
            }
            dummy = dummy->next->next;
        }
        Node* new_node = head->next;
        dummy = head;
        while(dummy != nullptr) {
            Node* copy = dummy->next;
            dummy->next = copy->next;
            if(copy->next != nullptr) {
                copy->next = dummy->next->next;
            }
            dummy = dummy->next;
        }
        return new_node;
    }
};
