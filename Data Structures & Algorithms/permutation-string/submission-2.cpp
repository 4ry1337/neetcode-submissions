class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    std::array<int, 26> f1{}, f2{};
    for (auto& c : s1) f1[c - 'a']++;
    for (size_t i{}; i < s2.size(); ++i) {
      f2[s2[i] - 'a']++;
      if (i >= s1.size()) f2[s2[i - s1.size()] - 'a']--;
      if (i >= s1.size() - 1 && f1 == f2) return true;
    }
    return false;
  }
};
