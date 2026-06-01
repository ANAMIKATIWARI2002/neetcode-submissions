class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int &area) {
        int m = grid[0].size();
        int n = grid.size();
        if( i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0) {
                return;
        }
        vis[i][j]=1;
        area++;

        for(auto d : dir) {
            dfs(grid, vis, i + d.first, j + d.second, area);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int area = 0;
        int finalArea = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    area = 0;
                    dfs(grid, vis, i, j, area);
                    finalArea = max(area, finalArea);
                }
            }
        }
        return finalArea;
    }
};
