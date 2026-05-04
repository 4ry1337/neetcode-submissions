/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int res;
    int goodNodes(TreeNode* root) {
        res = 0;
        dfs(root, -101);
        return res;
    }

    void dfs(TreeNode* root, int m) {
        if(!root) return;
        if(root->val >= m) {
            res++;
            m = root->val;
        }
        dfs(root->left, m);
        dfs(root->right, m);
    }
};
