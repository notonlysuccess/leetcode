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
		vector<Interval>::iterator iter = intervals.begin();
		while ( iter != intervals.end() ) {
			if (iter->start <= newInterval.start && newInterval.end <= iter->end) {
				return intervals;
			}
			if (iter->start <= newInterval.start && newInterval.start <= iter->end) {
				newInterval.start = iter->start;
				iter = intervals.erase(iter);
			} else if (iter->start <= newInterval.end && newInterval.end <= iter->end) {
				newInterval.end = iter->end;
				iter = intervals.erase(iter);
			} else if (newInterval.start <= iter->start && iter->end <= newInterval.end) {
				intervals.erase(iter);
			} else if (iter->start > newInterval.end) {
				intervals.insert(iter , newInterval);
				return intervals;
			} else {
				iter ++;
			}
 		}
 		intervals.insert(intervals.end() , newInterval);
		return intervals;
	}
};