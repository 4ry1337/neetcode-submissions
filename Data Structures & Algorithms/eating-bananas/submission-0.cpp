class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int l = 1;
        int r = *max_element(p.begin(), p.end());
        int res = r;
        while(l <= r) {
            int m = l + (r - l) / 2;
            long long sum = 0;
            for(int x : p) sum += ceil(static_cast<double>(x) / m);
            if(sum <= h) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};
