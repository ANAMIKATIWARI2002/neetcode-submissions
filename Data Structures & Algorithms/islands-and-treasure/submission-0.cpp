#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int R = grid.size();
        if (R == 0) return;
        int C = grid[0].size();

        queue<pair<int,int>> q;

        // Push all treasure cells (0) into the queue
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (auto d : dir) {
                int nr = r + d.first;
                int nc = c + d.second;

                // Only update traversable land cells (INF)
                if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
                    grid[nr][nc] == 2147483647) {
                    
                    grid[nr][nc] = grid[r][c] + 1;  // Distance from nearest treasure
                    q.push({nr, nc});
                }
            }
        }
    }
};
