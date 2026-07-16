class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if(!root) return 0;
    int res = 0;
    deque<pair<TreeNode*, int>> v{{root, 1}};
    while (!v.empty()) {
      auto& [curr, level] = v.front();
      res = max(res, level);
      if (curr->left) v.push_back({curr->left, level + 1});
      if (curr->right) v.push_back({curr->right, level + 1});
      v.pop_front();
    }
    return res;
  }
};
