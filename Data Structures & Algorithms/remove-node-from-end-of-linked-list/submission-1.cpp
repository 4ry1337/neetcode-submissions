class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return head;
    ListNode *dummy = new ListNode(0, head), *slow = dummy, *fast = dummy;
    while (fast) {
      fast = fast->next;
      if (n < 0) slow = slow->next;
      n--;
    }
    if (slow->next) {
      ListNode* temp = slow->next;
      slow->next = slow->next->next;
      delete temp;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};
