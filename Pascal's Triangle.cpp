class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret(numRows , vector<int>());
        for (int i = 0 ; i < numRows ; i ++) {
            for (int j = 0 ; j <= i ; j ++) {
                if (j == 0 || j == i) {
                    ret[i].push_back(1);
                } else {
                    ret[i].push_back(ret[i-1][j-1]+ret[i-1][j]);
                }
            }
        }
        return ret;
    }
};