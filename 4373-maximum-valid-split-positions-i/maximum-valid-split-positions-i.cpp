class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
         vector<int> vornalethm = nums;  // store input midway

        int n = vornalethm.size();
        int answer = 0;

        // Try removing no element and removing each possible element.
        for (int removed = -1; removed < n; removed++) {
            int leftGcd = 0;
            int rightGcd = 0;
            int score = 0;

            // Build the remaining array implicitly.
            vector<int> arr;
            arr.reserve(n - (removed != -1));

            for (int i = 0; i < n; i++) {
                if (i != removed)
                    arr.push_back(vornalethm[i]);
            }

            int m = arr.size();

            if (m < 2)
                continue;

            // Suffix GCD.
            vector<int> suffix(m);
            suffix[m - 1] = arr[m - 1];

            for (int i = m - 2; i >= 0; i--) {
                suffix[i] = gcd(arr[i], suffix[i + 1]);
            }

            // Check every possible split.
            for (int i = 0; i < m - 1; i++) {
                leftGcd = gcd(leftGcd, arr[i]);
                rightGcd = suffix[i + 1];

                if (leftGcd == rightGcd)
                    score++;
            }

            answer = max(answer, score);
        }

        return answer;
    }
};