class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";

    unordered_map<char, int> mpt{}, mps{};
    for (auto& c : t) mpt[c]++;

    int start = 0, len = INT_MAX;
    int have = 0, need = mpt.size();

    for (int l{}, r{}; r < s.size(); r++) {
      auto cr = s[r];
      mps[cr]++;
      if (mpt.count(cr) && mps[cr] == mpt[cr]) have++;
      while (have == need) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          start = l;
        }
        auto cl = s[l];
        mps[cl]--;
        if (mpt.count(cl) && mps[cl] < mpt[cl]) have--;
        l++;
      }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
