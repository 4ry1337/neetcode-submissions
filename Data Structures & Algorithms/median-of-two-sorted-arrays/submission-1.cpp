class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        vector<int>& a = n1;
        vector<int>& b = n2;
        int t = a.size() + b.size();
        int h = (t + 1) / 2;

        if(b.size() < a.size()) swap(a, b);
        
        int l = 0, r = a.size();
        while(l <= r) {
            int am = l + (r - l) / 2;
            int al = am > 0 ? a[am - 1] : INT_MIN;
            int ar = am < a.size() ? a[am] : INT_MAX;

            int bm = h - am;
            int bl = bm > 0 ? b[bm - 1] : INT_MIN;
            int br = bm < b.size() ? b[bm] : INT_MAX;

            if(al <= br && bl <= ar) {
                if(t % 2 != 0) return max(al, bl);
                return (max(al, bl) + min(ar, br)) / 2.0;
            } else if(al > br) {
                r = am - 1;
            } else {
                l = am + 1;
            }
        }
        return -1;
    }
};

// 1 2 3
// m = 2

// 1 3 2 4
// m = 2.5

// 