class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mp;
    for (const string &str : strs) {
      vector<int> v(26, 0);
      for (const unsigned char &c : str) {
        v[c - 'a']++;
      }
      string key = to_string(v[0]);
      for (int i = 1; i < 26; i++) {
        key += ',' + to_string(v[i]);
      }
      mp[key].push_back(str);
    }
    vector<vector<string>> res;
    for (const auto &pair : mp) {
      res.push_back(pair.second);
    }
    return res;
  }
};
