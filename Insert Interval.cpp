/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        for (auto iter = intervals.begin() ; iter != intervals.end() ; iter ++) {
            if (iter->end < newInterval.start) {
                ret.push_back(*iter);
            } else if (iter->start > newInterval.end) {
                ret.push_back(newInterval);
                ret.insert(ret.end() , iter , intervals.end());
                return ret;
            } else {
                newInterval.start = min(newInterval.start , iter->start);
                newInterval.end = max(newInterval.end , iter->end);
            }
        } 
        ret.push_back(newInterval);
        return ret;
    }
};