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
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<pair<int,int> > vec;
        for (int i = 0 ; i < intervals.size() ; i ++) {
            vec.push_back(make_pair(intervals[i].start , -1));
            vec.push_back(make_pair(intervals[i].end , 1));
        }
        sort(vec.begin() , vec.end());
        stack<int> st;
        vector<Interval> ret;
        for (int i = 0 ; i < vec.size() ; i ++) {
            if (vec[i].second == -1) {
                st.push(vec[i].first);
            } else {
                int val = st.top();
                st.pop();
                if (st.empty()) {
                    ret.push_back(Interval(val , vec[i].first));
                }
            }
        }
        return ret;
    }
};