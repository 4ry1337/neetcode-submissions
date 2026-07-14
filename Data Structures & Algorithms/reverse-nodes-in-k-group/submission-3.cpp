class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    int cnt = k;
    ListNode *res = head, *slow = head, *fast = head, *first = slow;
    while (fast) {
      if (cnt == 0) {
        ListNode *pf = first, *prev = nullptr;
        first = slow;
        while (slow != fast) {
          ListNode* next = slow->next;
          slow->next = prev;
          prev = slow;
          slow = next;
        }
        if (first != pf) {
          pf->next = prev;
        } else {
          res = prev;
        }
        first->next = slow;
        cnt = k;
      }
      fast = fast->next;
      cnt--;
    }
    if (cnt == 0) {
      ListNode *pf = first, *prev = nullptr;
      first = slow;
      while (slow != fast) {
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
      }
      if (first != pf) {
        pf->next = prev;
      } else {
        res = prev;
      }
      first->next = slow;
      cnt = k;
    }
    return res;
  }
};
