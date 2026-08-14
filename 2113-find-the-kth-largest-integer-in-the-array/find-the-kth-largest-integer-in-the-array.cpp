class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<
            string,
            vector<string>,
            function<bool(string, string)>
        > minHeap([](string a, string b) {
            if (a.length() != b.length()) {
                return a.length() > b.length();
            }
            return a > b;
        });

        for (string num : nums) {

            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};