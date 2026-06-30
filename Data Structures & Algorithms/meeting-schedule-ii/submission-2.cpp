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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;

        for (Interval interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int maxRooms = 0;
        int rooms = 0;
        int s = 0;
        int e = 0;

        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                s++;
            } else {
                e++;
                rooms--;
            }
        }

        return maxRooms;

        
    }
};
