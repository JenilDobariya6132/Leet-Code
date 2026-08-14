class Solution {
public:

    void solve(vector<vector<int>>& grid,
               int row,
               int col,
               int size,
               int& value) {

        if (size == 1) {
            grid[row][col] = value;
            value++;
            return;
        }

        int half = size / 2;

        solve(grid,
              row,
              col + half,
              half,
              value);

        solve(grid,
              row + half,
              col + half,
              half,
              value);

        solve(grid,
              row + half,
              col,
              half,
              value);

        solve(grid,
              row,
              col,
              half,
              value);
    }

    vector<vector<int>> specialGrid(int n) {

        int size = 1 << n;   

        vector<vector<int>> grid(
            size,
            vector<int>(size)
        );

        int value = 0;

        solve(grid, 0, 0, size, value);

        return grid;
    }
};