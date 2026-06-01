class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1️⃣ Build adjacency list & in-degree array
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1]; // b -> a
            adj[b].push_back(a);
            indegree[a]++;
        }

        // 2️⃣ Queue for nodes with 0 in-degree
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0; // number of courses processed

        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        // If all courses are processed, return true
        return count == numCourses;
    }
};
