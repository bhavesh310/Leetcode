class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // Treat '*' as ')'
                high++;  // Treat '*' as '('
            }

            // Even the maximum possible '(' count is negative
            if (high < 0)
                return false;

            // Minimum cannot be negative; use '*' as empty
            low = max(low, 0);
        }

        return low == 0;
    }
};