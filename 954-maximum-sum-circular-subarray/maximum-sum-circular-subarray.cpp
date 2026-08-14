class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;
        int currentMax = 0;
        int maxSum = INT_MIN;
        int currentMin = 0;
        int minSum = INT_MAX;

        for (int num : nums) {
            currentMax = max(num, currentMax + num);
            maxSum = max(maxSum, currentMax);
            currentMin = min(num, currentMin + num);
            minSum = min(minSum, currentMin);

            totalSum += num;
        }
        if (maxSum < 0) {
            return maxSum;
        }
        int circularSum = totalSum - minSum;

        return max(maxSum, circularSum);
    }
};