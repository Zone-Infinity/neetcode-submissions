class Solution {
   private:
    struct Compare {
        bool operator()(vector<int>& a, vector<int>& b) {
            int d1 = a[0] * a[0] + a[1] * a[1];
            int d2 = b[0] * b[0] + b[1] * b[1];

            return d1 > d2;
        }
    };

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        while(!pq.empty() && k--) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
