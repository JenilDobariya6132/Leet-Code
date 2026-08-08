class Solution {
public:
    vector<string> result;

    string letters[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index, string current) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        string possibleLetters = letters[digits[index] - '0'];

        for (char c : possibleLetters) {

            current.push_back(c);

            backtrack(digits, index + 1, current);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }

        backtrack(digits, 0, "");

        return result;
    }
};