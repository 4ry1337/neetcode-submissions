class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        vector<int> res(n.size(), 0);
        int pre = 1, suf = 1;
        for(int i = 0; i < n.size(); i++) {
            res[i] = pre;
            pre *= n[i];
        }
        for(int i = n.size() - 1; i > -1 ; i--) {
            res[i] *= suf;
            suf *= n[i];
        }
        return res;
    }
};