class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = earliest index in word1 from which
        // word2[i...] can be matched exactly.
        vector<int> suf(m, -1);

        int j = n - 1;

        for (int i = m - 1; i >= 0; --i) {
            while (j >= 0 && word1[j] != word2[i]) {
                --j;
            }

            if (j < 0) break;

            suf[i] = j;
            --j;
        }

        vector<int> ans;

        int p = 0;          // pointer in word2
        bool mismatch = false;

        for (int i = 0; i < n && p < m; ++i) {

            // Exact match
            if (word1[i] == word2[p]) {
                ans.push_back(i);
                ++p;
            }

            // Use the one allowed mismatch
            else if (!mismatch) {

                // If this is the last character, mismatch is always valid.
                if (p == m - 1) {
                    ans.push_back(i);
                    ++p;
                    mismatch = true;
                }

                // Otherwise, make sure the remaining part can
                // be matched exactly after i.
                else if (suf[p + 1] != -1 && suf[p + 1] > i) {
                    ans.push_back(i);
                    ++p;
                    mismatch = true;
                }
            }
        }

        if (ans.size() == m)
            return ans;

        return {};
    }
};