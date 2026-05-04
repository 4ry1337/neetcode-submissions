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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        return to_string(root->val) + ":" + serialize(root->left) + ":" + serialize(root->right);   
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data;
        vector<string> vals = split(data, ':');
        int i = 0;
        return dfs(vals, i);
    }

    TreeNode* dfs(vector<string> data, int& i) {
        if(data[i] == "N") {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(data[i]));
        i++;
        node->left = dfs(data, i);
        node->right = dfs(data, i);
        return node;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
};
