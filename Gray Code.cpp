class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int m = 1 << n;
        for (int i = 0 ; i < m ; i ++) {
            ret.push_back(i ^ (i >> 1));
        }
        return ret;
    }
};