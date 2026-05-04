class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int c[9][9] = {0};
        int r[9][9] = {0};
        int d[3][3][9] = {0};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(b[i][j] == '.') continue;
                if(r[i][b[i][j] - '1']++) return false;
                if(c[j][b[i][j] - '1']++) return false;
                if(d[i / 3][j / 3][b[i][j] - '1']++) return false;
            }
        }
        return true;
    }
};
