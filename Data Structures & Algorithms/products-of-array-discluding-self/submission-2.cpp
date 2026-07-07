class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& n) {
    vector<int> res(n.size());
    int pre = 1, post = 1;
    for (int i = 0; i < n.size(); ++i) {
      res[i] = pre;
      pre *= n[i];
    }
    for (int i = n.size() - 1; i >= 0; --i) {
      res[i] *= post;
      post *= n[i];
    }
    return res;
  }
};
