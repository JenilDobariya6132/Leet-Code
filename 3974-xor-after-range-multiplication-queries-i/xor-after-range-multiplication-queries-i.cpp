class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        const long long MOD = 1000000007;
        for (auto& query : queries) {

            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];
            for (int i = l; i <= r; i += k) {

                nums[i] = (long long)nums[i] * v % MOD;
            }
        }
        int answer = 0;

        for (int num : nums) {
            answer ^= num;
        }

        return answer;
    }
};