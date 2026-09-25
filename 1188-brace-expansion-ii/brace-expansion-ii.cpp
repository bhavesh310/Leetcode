class Solution {
public:
    string s;
    int i = 0;

    // Union of two sets
    set<string> unite(set<string> a, set<string> b) {
        a.insert(b.begin(), b.end());
        return a;
    }

    // Concatenate every string from a with every string from b
    set<string> multiply(const set<string>& a, const set<string>& b) {
        set<string> res;

        for (const string& x : a) {
            for (const string& y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    // Parse an expression
    set<string> parse() {
        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; // skip '{'

                set<string> inside = parse();

                i++; // skip '}'

                current = multiply(current, inside);
            }
            else if (s[i] == ',') {
                // Finish current concatenation
                result = unite(result, current);

                current = {""};
                i++;
            }
            else {
                // Normal character
                string ch(1, s[i]);
                set<string> temp = {ch};

                current = multiply(current, temp);
                i++;
            }
        }

        // Add final concatenation
        result = unite(result, current);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parse();

        return vector<string>(ans.begin(), ans.end());
    }
};