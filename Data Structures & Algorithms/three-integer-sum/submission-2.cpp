class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        vector<vector<int>> res;
        sort(n.begin(), n.end());
        for(int i = 0; i < n.size(); i++) {
            if(i > 0 && n[i] == n[i-1]) continue;
            int l = i + 1, r = n.size() - 1;
            while(l < r) {
                int sum = n[i] + n[l] + n[r];
                if(sum < 0) l++;
                else if(sum > 0) r--;
                else {
                    res.push_back({n[i], n[l], n[r]});
                    while(l < r && n[l] == n[l + 1]) l++;
                    while(l < r && n[r] == n[r - 1]) r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
