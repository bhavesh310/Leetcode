class Solution {
public:
    vector<string> ans;

    void backtrack(string &s, int open, int close, int n) {
        // A valid sequence of length 2*n is complete
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add opening parenthesis
        if (open < n) {
            s.push_back('(');
            backtrack(s, open + 1, close, n);
            s.pop_back();
        }

        // Add closing parenthesis only when it won't become invalid
        if (close < open) {
            s.push_back(')');
            backtrack(s, open, close + 1, n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        backtrack(s, 0, 0, n);
        return ans;
    }
};