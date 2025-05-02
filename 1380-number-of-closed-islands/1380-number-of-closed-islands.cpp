class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 0)
            return;
        grid[i][j] = -1; // mark water as visited
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    bool isClosedIsland(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        if (grid[i][j] == 1 || grid[i][j] == -1) return true;

        grid[i][j] = -1; // mark visited

        bool up = isClosedIsland(grid, i-1, j);
        bool down = isClosedIsland(grid, i+1, j);
        bool left = isClosedIsland(grid, i, j-1);
        bool right = isClosedIsland(grid, i, j+1);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    if (isClosedIsland(grid, i, j))
                        count++;
                }
            }
        }
        return count;
    }
};
