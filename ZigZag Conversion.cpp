class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        string ret;
        int n = s.length();
        for (int i = 0 ; i < nRows ; i ++) {
            if (i == 0 || i == nRows - 1) {
                for (int j = i ; j < n ; j += 2 * nRows - 2) {
                    ret += s[j];
                }
            } else {
                for (int j = i ; j < n ; j += 2 * nRows - 2) {
                    ret += s[j];
                    if (j + 2 * (nRows - i - 1) < n) {
                        ret += s[j + 2 * (nRows - i -1 )];
                    }
                }
            }
        }
        return ret;
    }
};