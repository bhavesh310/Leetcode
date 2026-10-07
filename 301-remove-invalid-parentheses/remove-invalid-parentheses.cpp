class Solution {
public:
    vector<string> ans;
    
    void dfs(string &s, int idx, int leftRem, int rightRem,
             int balance, string &cur) {
        
        if (idx == s.size()) {
            if (leftRem == 0 && rightRem == 0 && balance == 0) {
                ans.push_back(cur);
            }
            return;
        }

        char ch = s[idx];

        // Remove current parenthesis
        if (ch == '(' && leftRem > 0) {
            dfs(s, idx + 1, leftRem - 1, rightRem, balance, cur);
        }

        if (ch == ')' && rightRem > 0) {
            dfs(s, idx + 1, leftRem, rightRem - 1, balance, cur);
        }

        // Keep current character
        if (ch != '(' && ch != ')') {
            cur.push_back(ch);
            dfs(s, idx + 1, leftRem, rightRem, balance, cur);
            cur.pop_back();
        }
        else if (ch == '(') {
            cur.push_back(ch);
            dfs(s, idx + 1, leftRem, rightRem, balance + 1, cur);
            cur.pop_back();
        }
        else if (ch == ')' && balance > 0) {
            cur.push_back(ch);
            dfs(s, idx + 1, leftRem, rightRem, balance - 1, cur);
            cur.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0, rightRem = 0;

        // Find minimum number of '(' and ')' to remove
        for (char ch : s) {
            if (ch == '(') {
                leftRem++;
            }
            else if (ch == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        string cur;
        dfs(s, 0, leftRem, rightRem, 0, cur);

        // Remove duplicates
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};