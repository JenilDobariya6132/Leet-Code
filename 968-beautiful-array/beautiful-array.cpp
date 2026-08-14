class Solution {
public:
    vector<int> beautifulArray(int n) {

        vector<int> result = {1};

        while (result.size() < n) {

            vector<int> temp;
            for (int x : result) {
                int odd = 2 * x - 1;

                if (odd <= n) {
                    temp.push_back(odd);
                }
            }
            for (int x : result) {
                int even = 2 * x;

                if (even <= n) {
                    temp.push_back(even);
                }
            }

            result = temp;
        }

        return result;
    }
};