class Solution {
public:
    int search(vector<int>& n, int t) {
        int l = 0, r = n.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(n[m] == t) return m;
            if(n[l] <= n[m])  {
                if(n[m] < t || n[l] > t) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if(n[m] > t || n[r] < t) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
