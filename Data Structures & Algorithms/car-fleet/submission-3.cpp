class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        for(int i = 0; i < position.size(); i++) {
            car.push_back({position[i], speed[i]});
        }

        sort(car.begin(), car.end(), greater<>());

        int n = 0;
        double pt = 0;

         for (auto [pos, spd] : car) {
            double time = (double)(target - pos) / spd;

            if (time > pt) {
                n++;
                pt = time;
            }
        }

        return n;
    }
};
