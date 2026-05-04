class Solution {
public:
    void search(int open, int close, int n, vector<string>& res, string st) {
        if(open == close && open == n) {
            res.push_back(st);
            return;
        }

        if(open < n) {
            st += '(';
            search(open + 1, close, n, res, st);
            st.pop_back();        
        }
        if(close < open) {
            st +=')';
            search(open, close + 1, n, res, st);
            st.pop_back(); 
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        search(0, 0, n, res, "");
        return res;
    }
};
