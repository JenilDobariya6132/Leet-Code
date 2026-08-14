class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, pair<int, int>>
        > maxHeap;

        for (auto& point : points) {

            int x = point[0];
            int y = point[1];

            int distance = x * x + y * y;

            maxHeap.push({
                distance,
                {x, y}
            });
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;

        while (!maxHeap.empty()) {

            auto point = maxHeap.top().second;
            maxHeap.pop();

            result.push_back({
                point.first,
                point.second
            });
        }
        return result;
    }
};