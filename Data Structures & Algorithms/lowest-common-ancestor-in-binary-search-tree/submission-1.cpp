class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* curr = root;
    while (curr) {
      if ((p->val >= curr->val && curr->val >= q->val) ||
          (p->val <= curr->val && curr->val <= q->val)) {
        return curr;
      } else if (p->val > curr->val && curr->val < q->val) {
        curr = curr->right;
      } else if (p->val < curr->val && curr->val > q->val) {
        curr = curr->left;
      }
    }
    return root;
  }
};
