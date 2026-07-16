class Solution {
 private:
  int dfs(TreeNode* root, int& res) {
    if (!root) return 0;
    int val = root->val;
    int left_max = max(dfs(root->left, res), 0);
    int right_max = max(dfs(root->right, res), 0);
    res = max(res, val + left_max + right_max);
    return val + max(right_max, left_max);
  }

 public:
  int maxPathSum(TreeNode* root) {
    int res = root->val;
    dfs(root, res);
    return res;
  }
};
