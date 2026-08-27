class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int n = s.size();
        string prefix;

        // Try to make prefix equal to target
        int i = 0;

        while (i < n) {
            int x = target[i] - 'a';

            if (cnt[x] == 0)
                break;

            cnt[x]--;
            prefix += target[i];
            i++;
        }

        // target itself is possible, but we need STRICTLY greater
        if (i == n) {
            i--;

            char ch = prefix.back();
            prefix.pop_back();

            cnt[ch - 'a']++;
        }

        // Backtrack and try to make one position larger
        while (i >= 0) {

            int x = target[i] - 'a';

            // Find the smallest character > target[i]
            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] > 0) {
                    cnt[c]--;

                    string ans = prefix;
                    ans += char('a' + c);

                    // Remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        while (cnt[k] > 0) {
                            ans += char('a' + k);
                            cnt[k]--;
                        }
                    }

                    return ans;
                }
            }

            // Cannot increase at this position.
            // Restore the character and move backwards.
            i--;

            if (!prefix.empty()) {
                char ch = prefix.back();
                prefix.pop_back();
                cnt[ch - 'a']++;
            }
        }

        return "";
    }
};