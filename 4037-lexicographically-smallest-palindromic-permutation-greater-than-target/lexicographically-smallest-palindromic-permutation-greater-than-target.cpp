class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // Check if palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available in the left half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        auto build = [&](const string& left) {
            string ans = left;

            if (n % 2)
                ans += middle;

            for (int i = m - 1; i >= 0; i--)
                ans += left[i];

            return ans;
        };

        /*
            Try to match target's left half as much as possible.
        */
        vector<int> rem = halfCnt;
        string left;

        int fail = -1;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                fail = i;
                break;
            }

            left += target[i];
            rem[x]--;
        }

        /*
            If the whole left half matches target's left half,
            the palindrome may still be > target because of
            the right half.
        */
        if (fail == -1) {
            string candidate = build(left);

            if (candidate > target)
                return candidate;

            /*
                Exact palindrome == target, so we need the next
                larger permutation of the left half.
            */

            for (int i = m - 1; i >= 0; i--) {
                vector<int> available = rem;

                // Put back the character at i
                available[left[i] - 'a']++;

                // Try smallest character > target[i]
                for (int c = target[i] - 'a' + 1; c < 26; c++) {

                    if (available[c] == 0)
                        continue;

                    string newLeft = left.substr(0, i);
                    newLeft += char('a' + c);

                    available[c]--;

                    // Fill remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (available[j] > 0) {
                            newLeft += char('a' + j);
                            available[j]--;
                        }
                    }

                    return build(newLeft);
                }

                rem[left[i] - 'a']++;
            }

            return "";
        }

        /*
            We could match target only up to `fail`.

            First try to increase the character at `fail`.
            If that is impossible, move the pivot to the left.
        */

        for (int i = fail; i >= 0; i--) {

            vector<int> available = rem;

            // If i is inside the already matched prefix,
            // restore its character.
            if (i < (int)left.size())
                available[left[i] - 'a']++;

            // Try the smallest character greater than target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (available[c] == 0)
                    continue;

                string newLeft = left.substr(0, i);
                newLeft += char('a' + c);

                available[c]--;

                // Smallest possible suffix
                for (int j = 0; j < 26; j++) {
                    while (available[j] > 0) {
                        newLeft += char('a' + j);
                        available[j]--;
                    }
                }

                return build(newLeft);
            }

            // Move pivot left.
            if (i < (int)left.size())
                rem[left[i] - 'a']++;
        }

        return "";
    }
};