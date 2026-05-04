class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int m = 0;
        while(l < r) {
            if(h[r] < h[l]) {
                int w = h[r] * (r - l);
                m = max(m, w);
                r--;
            } else {
                int w = h[l] * (r - l);
                m = max(m, w);
                l++;
            }
        }
        return m;
    }
};
