class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<array<int, 26>, vector<int>> mp;
    for (int i{}; i < strs.size(); ++i) {
      array<int, 26> freq{};
      for (auto& c : strs[i]) {
        freq[c - 'a']++;
      }
      mp[freq].push_back(i);
    }
    vector<vector<string>> res;
    for (auto& f : mp) {
      vector<string> temp;
      for (auto& index : f.second) {
        temp.push_back(strs[index]);
      }
      res.push_back(temp);
    }
    return res;
  }
};
