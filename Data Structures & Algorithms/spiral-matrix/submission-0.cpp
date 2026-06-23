class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        pair<int, int> node = {0, 0};
        int m = matrix.size(), n = matrix[0].size();

        int count = m * n;

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currD = 0;

        vector<int> ans;
        while (count--) {
            ans.push_back(matrix[node.first][node.second]);
            matrix[node.first][node.second] = INT_MIN;
            
            pair<int, int> newNode = {node.first + dirs[currD].first,
                                      node.second + dirs[currD].second};

            if (newNode.first < 0 || newNode.second < 0 || newNode.first >= m ||
                newNode.second >= n || matrix[newNode.first][newNode.second] == INT_MIN) {
                currD = (currD + 1) % 4;
            }

            node = {node.first + dirs[currD].first, node.second + dirs[currD].second};
        }

        return ans;
    }
};
