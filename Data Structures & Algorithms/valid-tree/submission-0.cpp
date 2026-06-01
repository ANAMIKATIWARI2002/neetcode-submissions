class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;

    bool dfs(int node, int parent) {
        visited[node] = 1;

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                if (!dfs(neigh, node)) return false;
            }
            else if (neigh != parent) {
                return false; // cycle
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        adj.assign(n, {});
        visited.assign(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if (!dfs(0, -1)) return false;

        for (int i = 0; i < n; i++)
            if (!visited[i]) return false;

        return true;
    }
};
