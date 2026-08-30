class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

        // Bishops always stay on the same color.
        if ((sr + sc) % 2 != (tr + tc) % 2)
            return -1;

        // Same diagonal -> one move.
        if (abs(sr - tr) == abs(sc - tc))
            return 1;

        // Same color but different diagonal -> two moves.
        return 2;
    }
};