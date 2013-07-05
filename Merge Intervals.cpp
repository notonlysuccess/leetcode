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
    void Merge(vector<Interval> &ret , Interval &interval) {
        for (int i = 0 ; i < ret.size() ; i ++) {
            if (ret[i].start <= interval.start && interval.start <= ret[i].end) {
                interval.start = ret[i].start;
            }
            if (ret[i].start <= interval.end && interval.end <= ret[i].end) {
                interval.end = ret[i].end;
            }
            if (interval.start <= ret[i].start && ret[i].end <= interval.end) {
                ret.erase(ret.begin() + i);
                i --;
                continue;
            }
            if (interval.end <= ret[i].start) {
                ret.insert(ret.begin() + i , interval);
                return ;
            }
        }
        ret.push_back(interval);
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        for (int i = 0 ; i < intervals.size() ; i ++) {
            Merge(ret , intervals[i]);
        }
        return ret;
    }
};