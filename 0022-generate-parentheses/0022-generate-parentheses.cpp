class Solution {
public:
    void dfs(string s, int open, int close, int n, vector<string>& res) {
        if (s.length() == 2 * n) {
            res.push_back(s);
            return;
        }

        if (open < n)
            dfs(s + '(', open + 1, close, n, res);

        if (close < open)
            dfs(s + ')', open, close + 1, n, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", 0, 0, n, res);
        return res;
    }
};