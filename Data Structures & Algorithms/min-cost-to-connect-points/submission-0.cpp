class Solution {
    // Prim's Algorithm.
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> vis(n, false);

        minDist[0] = 0;

        int result = 0;

        for (int i = 0; i < n; i++) {

            int u = -1;

            // Pick minimum distance unvisited node
            for (int j = 0; j < n; j++) {
                if (!vis[j] &&
                    (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            vis[u] = true;
            result += minDist[u];

            // Update distances
            for (int v = 0; v < n; v++) {

                if (!vis[v]) {

                    int dist =
                        abs(points[u][0] - points[v][0]) +
                        abs(points[u][1] - points[v][1]);

                    minDist[v] =
                        min(minDist[v], dist);
                }
            }
        }

        return result;
    }
};