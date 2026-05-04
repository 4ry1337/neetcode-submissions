class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp; 
public:
    TimeMap() {}
    
    void set(string k, string v, int t) {
        mp[k].push_back({t, v});
    }
    
    string get(string k, int t) {
        auto n = mp[k];
        int l = 0, r = n.size() - 1;
        string res = "";
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(n[m].first <= t) {
                res = n[m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};
