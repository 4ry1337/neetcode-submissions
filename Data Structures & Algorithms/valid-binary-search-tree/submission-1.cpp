class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    queue<tuple<TreeNode*, long, long>> v({{root, LONG_MIN, LONG_MAX}});
    while (!v.empty()) {
      auto [curr, min, max] = v.front();
      v.pop();
      if (curr->val <= min || curr->val >= max) return false;
      if (curr->left) v.push({curr->left, min, curr->val});
      if (curr->right) v.push({curr->right, curr->val, max});
    }
    return true;
  }
};
