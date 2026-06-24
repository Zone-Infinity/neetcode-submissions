class Solution {
   private:
    bool dfs(int curr, int target, unordered_map<int, vector<int>>& adj,
             unordered_set<int>& visited) {
        if (curr == target) return true;

        visited.insert(curr);

        for (int nei : adj[curr]) {
            if (!visited.count(nei)) {
                if (dfs(nei, target, adj, visited)) return true;
            }
        }

        return false;
    }

   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            unordered_set<int> visited;

            if (dfs(u, v, adj, visited)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
