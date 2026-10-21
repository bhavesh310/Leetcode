
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Check if already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // Cannot sort a reversed string of length 2
        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Minimum character at start or maximum at end
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Minimum or maximum character in the middle
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        // Neither extreme character is at a boundary or middle
        return 3;
    }
};
