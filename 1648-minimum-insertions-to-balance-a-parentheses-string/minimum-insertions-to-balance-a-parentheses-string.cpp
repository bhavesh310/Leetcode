
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;

                // Previous opening needs two closing brackets.
                // If one closing bracket is pending, insert it.
                if (open > 1) {
                    // No action needed here.
                }
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++; // Consume the pair ))
                } else {
                    ans++; // Insert the missing )
                }

                if (open > 0) {
                    open--;
                } else {
                    ans++; // Insert a missing (
                }
            }
        }

        return ans + 2 * open;
    }
};