//DFS: Space: O[(V+E)]
//Time: O[(V+E)]

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // 1️⃣ Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // 2️⃣ DFS traversal
        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                components++;  // Each DFS call = one connected component
            }
        }

        return components;
    }
};


//Using DSU: Disjoint set union.

//O[V+E alpha(n)]: time
//O[n]: Space


// class Solution {
// public:
//     vector<int> parent, rank;

//     int find(int x) {
//         if (parent[x] != x)
//             parent[x] = find(parent[x]);  // Path compression
//         return parent[x];
//     }

//     void unite(int a, int b, int& components) {
//         int pa = find(a);
//         int pb = find(b);

//         if (pa == pb) return;

//         // Union by rank
//         if (rank[pa] < rank[pb]) {
//             parent[pa] = pb;
//         } else if (rank[pa] > rank[pb]) {
//             parent[pb] = pa;
//         } else {
//             parent[pb] = pa;
//             rank[pa]++;
//         }

//         components--;  // merged two components
//     }

//     int countComponents(int n, vector<vector<int>>& edges) {
//         parent.resize(n);
//         rank.assign(n, 0);

//         for (int i = 0; i < n; i++)
//             parent[i] = i;

//         int components = n;

//         for (auto& e : edges) {
//             unite(e[0], e[1], components);
//         }

//         return components;
//     }
// };
