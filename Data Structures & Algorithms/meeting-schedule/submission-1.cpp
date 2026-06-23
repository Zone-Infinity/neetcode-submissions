/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) return true;
        vector<pair<int, int>> inters;
        for (auto i : intervals) {
            inters.push_back({i.start, i.end});
        }

        sort(inters.begin(), inters.end());

        for (int i = 0; i < inters.size() - 1; i++) {
            if (inters[i].second > inters[i + 1].first) return false;
        }

        return true;
    }
};
