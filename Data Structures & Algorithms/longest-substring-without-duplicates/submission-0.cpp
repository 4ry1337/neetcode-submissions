class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 0;
        unordered_set<int> set;
        while(r < s.size()) {
            if(set.count(s[r])) {
                set.erase(s[l++]);
            } else {
                res = max(res, r - l + 1);
                set.insert(s[r++]);
            }
        }
        return res;
    }
};
