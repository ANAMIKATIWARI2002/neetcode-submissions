class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) { int a = pre[0], b = pre[1]; // b -> a 
            adj[b].push_back(a); 
            indegree[a]++; 
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            count++;

            for(auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if(count != numCourses) return {};
        else return topo;


    }
};
