class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> v({root});
    while (!v.empty()) {
      size_t size = v.size();
      for (size_t i{}; i++ < size;) {
        TreeNode* curr = v.front();
        v.pop();
        if (i == size) res.push_back(curr->val);
        if (curr->left) v.push(curr->left);
        if (curr->right) v.push(curr->right);
      }
    }
    return res;
  }
};
