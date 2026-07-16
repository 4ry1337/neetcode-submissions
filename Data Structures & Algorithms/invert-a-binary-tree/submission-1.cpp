class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    deque<TreeNode*> v{root};
    while (!v.empty()) {
      TreeNode* curr = v.front();
      swap(curr->left, curr->right);
      if (curr->left) v.push_back(curr->left);
      if (curr->right) v.push_back(curr->right);
      v.pop_front();
    }
    return root;
  }
};
