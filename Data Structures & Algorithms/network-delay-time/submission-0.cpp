class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> distance(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        distance[k] = 0;

        while (!q.empty()) {
            int node = q.top().second;
            int time = q.top().first;
            q.pop();

            if (time > distance[node]) continue;

            for (auto aNode : adj[node]) {
                int newTime = time + aNode.second;

                if (newTime < distance[aNode.first]) {
                    distance[aNode.first] = newTime;
                    q.push({newTime, aNode.first});
                }
            }
        }
        
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) return -1;
            ans = max(ans, distance[i]);
        }

        return ans;
    }
};
