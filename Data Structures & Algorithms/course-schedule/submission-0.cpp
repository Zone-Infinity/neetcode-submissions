class Solution {
private:
bool dfs(int course, unordered_map<int, vector<int>>& preq, unordered_set<int>& visited, unordered_set<int>& visiting) {
    if(visited.count(course)) return true;
    if(visiting.count(course)) return false;
    visiting.insert(course);

    for(int c : preq[course]) {
        if(!dfs(c, preq, visited, visiting))
            return false;
    }

    visiting.erase(course);
    visited.insert(course);
    return true;
}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> visited;
        unordered_set<int> visiting;

        unordered_map<int, vector<int>> preq;
        for(auto pre: prerequisites) {
            preq[pre[0]].push_back(pre[1]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, preq, visited, visiting)) return false;
        }

        return true;
    }
};
