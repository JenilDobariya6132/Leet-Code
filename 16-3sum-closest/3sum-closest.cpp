class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                long long sum = (long long)nums[i]
                              + nums[left]
                              + nums[right];
                if (abs((long long)target - sum) <
                    abs((long long)target - closest)) {

                    closest = (int)sum;
                }
                if (sum == target) {
                    return target;
                }
                if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return closest;
    }
};