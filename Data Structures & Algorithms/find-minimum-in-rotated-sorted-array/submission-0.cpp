class Solution {
public:
    int findMin(vector<int> &n) {
        int l = 0, r = n.size() - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(n[m] < n[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return n[l];
    }
};
