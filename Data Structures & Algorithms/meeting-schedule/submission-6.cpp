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
        if (intervals.size() <= 1) {
            return true;
        }

        bool noOverlap = true;
        // sort(intervals.start(), intervals.end());

        for (int i = 0; i < intervals.size() - 1; i++) {
            for (int j = i + 1; j < intervals.size(); j++) {
                if (i != j && intervals[i].start < intervals[j].end && intervals[j].start < intervals[i].end) {
                    noOverlap = false;
                    return false;
                }
            }
        }

        return noOverlap;
    }
};
