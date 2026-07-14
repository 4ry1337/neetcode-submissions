class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int res = 0, l = 0, r = 0;
    unordered_set<char> st;
    while (r < s.size()) {
      if (st.find(s[r]) != st.end()) {
        st.erase(s[l++]);
      } else {
        res = max(res, r - l + 1);
        st.insert(s[r++]);
      }
    }
    return res;
  }
};
