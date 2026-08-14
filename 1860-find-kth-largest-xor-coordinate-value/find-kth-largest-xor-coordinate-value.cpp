class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<vector<int>> prefix(rows + 1,
                                   vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; i++) {

            for (int j = 1; j <= cols; j++) {

                prefix[i][j] =
                    prefix[i - 1][j] ^
                    prefix[i][j - 1] ^
                    prefix[i - 1][j - 1] ^
                    matrix[i - 1][j - 1];
                minHeap.push(prefix[i][j]);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }

        return minHeap.top();
    }
};