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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int last = -1;
            for(int i = q.size(); i > 0; i--) {
                TreeNode* s = q.front(); q.pop();
                if(s) {
                    last = s->val;
                    q.push(s->left);
                    q.push(s->right);
                }
            }
            if(last != -1) res.push_back(last);
        }
        return res;
    }
};
