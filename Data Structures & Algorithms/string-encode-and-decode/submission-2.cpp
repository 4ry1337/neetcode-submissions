class Solution {
 public:
  string encode(vector<string>& strs) {
    string res = "";
    for (auto& str : strs) {
      res += to_string(str.size());
      res += '#';
      res += str;
    }
    return res;
  }

  vector<string> decode(string s) {
    vector<string> res;
    int i{};
    while (i < s.size()) {
      int size = 0;
      while (i < s.size() && s[i] != '#') {
        size *= 10;
        size += s[i] - '0';
        i++;
      }
      i++;
      res.push_back(s.substr(i, size));
      i += size;
    }
    return res;
  }
};
