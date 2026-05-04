class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res = 0, l = 0;
        for(int r = 1; r < p.size(); r++) {
            if(p[l] < p[r]) {
                int profit = p[r] - p[l];
                res = max(res, profit);
            } else {
                l = r;
            }
        }
        return res;
    }
};
