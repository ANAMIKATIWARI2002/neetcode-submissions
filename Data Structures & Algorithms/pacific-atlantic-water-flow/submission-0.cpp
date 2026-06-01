class Solution {
    int m, n;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis) {

        vis[r][c] = 1;

        for (auto d : dir) {
            int nr = r + d.first;
            int nc = c + d.second;

            if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(nr, nc, heights, vis);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        // Pacific borders
        for (int i = 0; i < m; i++)
            dfs(i, 0, heights, pac);

        for (int j = 0; j < n; j++)
            dfs(0, j, heights, pac);

        // Atlantic borders
        for (int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atl);

        for (int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atl);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
