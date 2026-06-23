class CountSquares {
   private:
    unordered_map<int, unordered_map<int, int>> points;
    vector<pair<int, int>> pts;

   public:
    CountSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];

        pts.push_back({x, y});
        points[x][y]++;
    }

    int count(vector<int> point) {
        int px = point[0], py = point[1];
        int ans = 0;

        for (auto [x, y] : pts) {
            if (x == px || y == py) continue;

            if (abs(x - px) != abs(y - py)) continue;

            ans += points[px][y] * points[x][py];
        }

        return ans;
    }
};
