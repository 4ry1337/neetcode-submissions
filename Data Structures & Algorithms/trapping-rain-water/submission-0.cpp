class Solution {
public:
    int trap(vector<int>& h) {
        if (h.empty()) return 0;

        int res = 0;
        
        int l = 0, r = h.size() - 1;
        int lm = h[l], rm = h[r];
        while(l < r) {
            if(lm < rm) {
                l++;
                lm = max(lm, h[l]);
                res += lm - h[l];
            } else {
                r--;
                rm = max(rm, h[r]);
                res += rm - h[r];
            }
        }

        return res;
    }
};
