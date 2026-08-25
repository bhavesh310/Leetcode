class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());

        for (int i = 1; ; i++) {
            int multiple = k * i;

            if (!s.count(multiple)) {
                return multiple;
            }
        }
    }
};