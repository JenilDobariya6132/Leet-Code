class Solution {
public:
    const int MOD = 1337;
    int modPow(int a, int b) {

        long long result = 1;

        a %= MOD;

        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {

        a %= MOD;

        int result = 1;

        for (int digit : b) {
            result = (modPow(result, 10) * modPow(a, digit)) % MOD;
        }
        return result;
    }
};