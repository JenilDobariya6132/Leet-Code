class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int answer = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;

            int evenCount = 0;
            int oddCount = 0;

            for (int j = i; j < n; j++) {
                if (seen.find(nums[j]) == seen.end()) {

                    seen.insert(nums[j]);

                    if (nums[j] % 2 == 0) {
                        evenCount++;
                    }
                    else {
                        oddCount++;
                    }
                }
                if (evenCount == oddCount) {
                    answer = max(answer, j - i + 1);
                }
            }
        }

        return answer;
    }
};