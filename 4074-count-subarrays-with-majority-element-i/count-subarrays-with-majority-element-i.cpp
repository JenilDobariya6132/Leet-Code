class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        int answer = 0;

        for (int i = 0; i < n; i++) {

            int countTarget = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    countTarget++;
                }

                int length = j - i + 1;
                if (countTarget * 2 > length) {
                    answer++;
                }
            }
        }

        return answer;
    }
};