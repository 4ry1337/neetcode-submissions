class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char, int> mp, curr;
        for(auto c : t) mp[c]++;

        int start = 0, len = INT_MAX;
        int have = 0, need = mp.size();
        
        int l = 0;
        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            curr[c]++;
            if(mp.count(c) && curr[c] == mp[c]) have++;
            while(have == need) {
                if((r - l + 1) < len) {
                    len = r - l + 1;
                    start = l;
                }
                curr[s[l]]--;
                if(mp.count(s[l]) && curr[s[l]] < mp[s[l]]) have--;
                l++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
