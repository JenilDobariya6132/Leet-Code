class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.length();
        int answer = 0;
        for (int unique = 1; unique <= 26; unique++) {

            vector<int> freq(26, 0);

            int left = 0;
            int right = 0;

            int uniqueCount = 0;
            int countAtLeastK = 0;

            while (right < n) {
                if (freq[s[right] - 'a'] == 0) {
                    uniqueCount++;
                }

                freq[s[right] - 'a']++;

                if (freq[s[right] - 'a'] == k) {
                    countAtLeastK++;
                }

                right++;
                while (uniqueCount > unique) {

                    if (freq[s[left] - 'a'] == k) {
                        countAtLeastK--;
                    }

                    freq[s[left] - 'a']--;

                    if (freq[s[left] - 'a'] == 0) {
                        uniqueCount--;
                    }

                    left++;
                }
                if (uniqueCount == unique &&
                    uniqueCount == countAtLeastK) {

                    answer = max(answer, right - left);
                }
            }
        }

        return answer;
    }
};