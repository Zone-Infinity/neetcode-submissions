class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if(visited[node]) return false;
        visited[node] = 1;

        for(int e : adj[node]) {
            dfs(e, adj, visited);
        }

        return true;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n);

        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int components = 0;
        for(int i = 0; i < n; i++) {
            if(dfs(i, adj, visited)) components++;
        }

        return components;
    }
};
