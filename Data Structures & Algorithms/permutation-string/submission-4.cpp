class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    array<int, 26> f1{}, f2{};
    for (auto& c : s1) f1[c - 'a']++;
    for (int i{}; i < s2.size(); ++i) {
      f2[s2[i] - 'a']++;
      if (s1.size() <= i) f2[s2[i - s1.size()] - 'a']--;
      if (s1.size() - 1 <= i && f1 == f2) return true;
    }
    return false;
  }
};
