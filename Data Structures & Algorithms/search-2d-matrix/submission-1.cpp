class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int row = mat.size() - 1, col = mat[0].size() - 1;
        int l = 0, r = row;
        row = -1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(mat[m][0] <= t && t <= mat[m][col]) {
                row = m;
                break;
            } else if(mat[m][0] > t) {
                r = m - 1;
            } else if(mat[m][col] < t) {
                l = m + 1;
            }
        }
        if(row == -1) return false;
        l = 0, r = col;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(mat[row][m] == t) return true;
            else if(mat[row][m] > t) r = m - 1;
            else l = m + 1;
        }
        return false;
    }
};