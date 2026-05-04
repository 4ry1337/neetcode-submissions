class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        unordered_map<int, int> mp;
        for(int i = 0; i < n.size(); i++) {
            if(mp.count(n[i])) {
                return {mp[n[i]], i + 1};
            }
            mp[t - n[i]] = i + 1;
        }
        return {};
    }
};
