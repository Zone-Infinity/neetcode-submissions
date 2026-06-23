class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        for(int i = 0; i < position.size(); i++) {
            car.push_back({position[i], speed[i]});
        }

        sort(car.begin(), car.end(), greater<>());

        int n = 1;
        double pt = (target - car[0].first) * 1.0 / car[0].second;
        for(int i = 1; i < car.size(); i++) {
            double t = (target - car[i].first) * 1.0 / car[i].second;
            if(pt < t) {
                n++;
                pt = t;
            }
        }

        return n;
    }
};
