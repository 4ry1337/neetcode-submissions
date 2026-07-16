class Solution {
 private:
  int pre_i = 0;
  unordered_map<int, int> indeces;

  TreeNode* dfs(vector<int>& p, int l, int r) {
    if (l > r) return nullptr;
    int val = p[pre_i++];
    TreeNode* root = new TreeNode(val);
    int mid = indeces[val];
    root->left = dfs(p, l, mid - 1);
    root->right = dfs(p, mid + 1, r);
    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int len = preorder.size();
    for (int i{}; i < len; ++i) indeces[inorder[i]] = i;
    return dfs(preorder, 0, len - 1);
  }
};
