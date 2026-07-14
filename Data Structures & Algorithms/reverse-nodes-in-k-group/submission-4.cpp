class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    int cnt = k;
    ListNode* res = head;
    ListNode *g = head, *gp = g, *gn = head;
    while (true) {
      if (cnt == 0) {
        ListNode *prev = nullptr, *curr = g;
        while (curr != gn) {
          ListNode* next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
        }
        if (gp != g) {
          gp->next = prev;
          gp = g;
        } else {
          res = prev;
        }
        g->next = gn;
        g = curr;
        cnt = k;
      }
      if(!gn) break;
      gn = gn->next;
      cnt--;
    }
    return res;
  }
};
