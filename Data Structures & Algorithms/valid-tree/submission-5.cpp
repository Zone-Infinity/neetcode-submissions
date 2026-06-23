class Solution {
   private:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;

        for (int c : adj[node]) {
            if (c == parent) continue;
            if (visited[c]) return false;
            if (!dfs(c, node, adj, visited)) return false;
        }

        return true;
    }

   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);
        if(!dfs(0, -1, adj, visited)) return false;

        for(auto v : visited) {
            if(!v) return false;
        }

        return true;
    }
};
