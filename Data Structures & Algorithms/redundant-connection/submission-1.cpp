class Solution {
    vector<int> parent, rankv;

    int findParent(int node) {
        if (parent[node] != node) {
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }

    bool unite(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);

        if (pa == pb) return true;

        if (rankv[pa] < rankv[pb]) {
            parent[pa] = pb;
        } 
        else if (rankv[pa] > rankv[pb]) {
            parent[pb] = pa;
        } 
        else {
            parent[pb] = pa;
            rankv[pa]++;
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rankv.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto& e : edges) {
            if (unite(e[0], e[1])) return e;
        }

        return {};
    }
};
