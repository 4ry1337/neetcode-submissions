class Solution {
 public:
  ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0), *curr = dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
    if (l1 != nullptr) {
      curr->next = l1;
    } else {
      curr->next = l2;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;

    for (int step = 1; step < lists.size(); step *= 2) {
      for (int i{}; i + step < lists.size(); i += step * 2) {
        lists[i] = merge(lists[i], lists[i + step]);
      }
    }

    return lists[0];
  }
};
