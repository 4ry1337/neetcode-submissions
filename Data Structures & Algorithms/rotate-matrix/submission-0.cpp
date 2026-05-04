class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        reverse(m.begin(), m.end());
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                swap(m[i][j], m[j][i]);
            }
        }
    }
};
/*
0 0 0 1
1 0 1 1
*/
