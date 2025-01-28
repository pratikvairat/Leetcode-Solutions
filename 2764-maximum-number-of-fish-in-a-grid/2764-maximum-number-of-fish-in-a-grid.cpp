class Solution {
public:
    int solve(vector<vector<int>> &grid, int n, int m, int i, int j) {
       
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            return 0;
        }

        
        int fish = grid[i][j];

       
        grid[i][j] = 0;

        
        fish += solve(grid, n, m, i + 1, j); // Down
        fish += solve(grid, n, m, i - 1, j); // Up
        fish += solve(grid, n, m, i, j + 1); // Right
        fish += solve(grid, n, m, i, j - 1); // Left

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxFish = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, solve(grid, n, m, i, j));
                }
            }
        }
        return maxFish;
    }
};
