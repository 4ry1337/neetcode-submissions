class Solution {
 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot) return true;
    if (!root) return false;
    if (isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

  bool isSameTree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) return true;
    if (root && subRoot && root->val == subRoot->val) {
      return isSameTree(root->left, subRoot->left) &&
             isSameTree(root->right, subRoot->right);
    }

    return false;
  }
};
