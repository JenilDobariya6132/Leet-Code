class Solution {
public:
    string longestNiceSubstring(string s) {

        if (s.length() < 2) {
            return "";
        }
        unordered_set<char> chars(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++) {

            char c = s[i];

            if (chars.count(tolower(c)) == 0 ||
                chars.count(toupper(c)) == 0) {

                string left = longestNiceSubstring(
                    s.substr(0, i)
                );

                string right = longestNiceSubstring(
                    s.substr(i + 1)
                );
                if (left.length() >= right.length()) {
                    return left;
                }
                else {
                    return right;
                }
            }
        }
        return s;
    }
};