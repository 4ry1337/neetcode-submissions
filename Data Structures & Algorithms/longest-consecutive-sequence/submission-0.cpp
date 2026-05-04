class Solution {
public:
  int longestConsecutive(vector<int>& n) {
    int res = 0;
    unordered_map<int, int> mp;
    for(int x : n) {
        if(!mp[x]) {
            mp[x] = mp[x - 1] + mp[x + 1] + 1;
            mp[x - mp[x - 1]] = mp[x];
            mp[x + mp[x + 1]] = mp[x];
            res = max(res, mp[x]);
        }
    }
    return res;
  }
};
