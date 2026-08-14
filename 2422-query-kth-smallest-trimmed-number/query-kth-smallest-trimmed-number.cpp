class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& queries) {

        vector<int> answer;

        for (auto& query : queries) {

            int k = query[0];
            int trim = query[1];
            vector<pair<string, int>> arr;

            for (int i = 0; i < nums.size(); i++) {

                string trimmed =
                    nums[i].substr(nums[i].size() - trim);

                arr.push_back({trimmed, i});
            }
            sort(arr.begin(), arr.end(),
                 [](const pair<string, int>& a,
                    const pair<string, int>& b) {

                if (a.first != b.first) {
                    return a.first < b.first;
                }

                return a.second < b.second;
            });
            answer.push_back(arr[k - 1].second);
        }

        return answer;
    }
};