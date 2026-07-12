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
 public:
  void reorderList(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *prev = nullptr;
    while (slow != nullptr) {
      ListNode* next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }
    fast = head;
    while (fast->next != prev && fast != prev) {
      ListNode* fn = fast->next,* pn = prev->next;

      fast->next = prev;
      prev->next = fn;

      fast = fn;
      prev = pn;
    }
  }
};

