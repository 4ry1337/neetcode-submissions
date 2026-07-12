class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *curr = slow, *prev = nullptr;
    while (curr != nullptr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    ListNode *h1 = head, *h2 = prev;
    while (h1->next != h2 && h1 != h2) {
      ListNode *h1_next = h1->next, *h2_next = h2->next;

      h1->next = h2;
      h2->next = h1_next;

      h1 = h1_next;
      h2 = h2_next;
    }
  }
};
