
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long mn = min(need1, need2);

        // Case 1: Buy individual items only
        long long costA = 1LL * need1 * cost1
                        + 1LL * need2 * cost2;

        // Case 2: Buy only combined items
        long long costB = 1LL * max(need1, need2) * costBoth;

        // Case 3: Buy combined items first,
        // then purchase remaining individual items
        long long costC = mn * costBoth
                        + 1LL * (need1 - mn) * cost1
                        + 1LL * (need2 - mn) * cost2;

        return min({costA, costB, costC});
    }
};
