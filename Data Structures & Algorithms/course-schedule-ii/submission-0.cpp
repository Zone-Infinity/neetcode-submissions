class Solution {
private:
    bool dfs(int course,
             vector<vector<int>>& preq,
             vector<int>& state,
             vector<int>& order) {
        
        if (state[course] == 2) return true;   // already processed
        if (state[course] == 1) return false;  // cycle detected

        state[course] = 1; // visiting

        for (int c : preq[course]) {
            if (!dfs(c, preq, state, order))
                return false;
        }

        state[course] = 2; // visited
        order.push_back(course); // add after prerequisites

        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preq(numCourses);

        for (const auto& pre : prerequisites) {
            preq[pre[0]].push_back(pre[1]);
        }

        vector<int> state(numCourses, 0);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, preq, state, order))
                return {};
        }

        return order;
    }
};