class Solution {
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        // boundary + visited + water check
        if (i < 0 || j < 0 || i >= m || j >= n ||
            vis[i][j] || grid[i][j] == '0')
            return;

        vis[i][j] = 1;

        for (auto d : dir) {
            dfs(i + d.first, j + d.second, grid, vis);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};
