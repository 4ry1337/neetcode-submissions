class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> f1{}, f2{};
    for (auto& c : s1) f1[c]++;

    int l = 0, r = 0;
    while (r < s2.size()) {
      f2[s2[r]]++;
      if (s1.size() < r - l + 1) {
        f2[s2[l]]--;
        if (f2[s2[l]] == 0) f2.erase(s2[l]);
        l++;
      }
      if (f1 == f2) return true;
      r++;
    }
    return false;
  }
};
