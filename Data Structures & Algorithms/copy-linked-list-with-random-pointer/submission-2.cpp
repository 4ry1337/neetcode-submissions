class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    Node* curr = head;
    while (curr) {
      Node* prev_next = curr->next;
      Node* new_next = new Node(curr->val);
      new_next->next = prev_next;
      new_next->random = curr->random;
      curr->next = new_next;
      curr = prev_next;
    }
    curr = head->next;
    while (curr) {
      if (curr->random) curr->random = curr->random->next;
      curr = curr->next ? curr->next->next : nullptr;
    }
    Node* res = head->next;
    curr = head;
    while (curr) {
      Node* new_node = curr->next;
      curr->next = new_node->next;
      curr = curr->next;
      new_node->next = curr ? curr->next : nullptr;
    }
    return res;
  }
};
