class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<int, int> mp;
        for(const char& c : s) {
            mp[(unsigned char)c]++;
        }
        for(const char& c : t) {
            if(--mp[(unsigned char)c] < 0) {
                return false;
            }
        }
        return true;
    }
};
