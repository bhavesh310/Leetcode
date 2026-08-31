class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (!head || !head->next || !head->next->next)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next) {
            int nextVal = curr->next->val;

            // Check if curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > nextVal) ||
                (curr->val < prev->val && curr->val < nextVal);

            if (isCritical) {
                if (first == -1) {
                    // First critical point
                    first = pos;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Fewer than two critical points
        if (first == -1 || first == last)
            return ans;

        // Maximum distance is between first and last critical points
        ans[0] = minDist;
        ans[1] = last - first;

        return ans;
    }
};