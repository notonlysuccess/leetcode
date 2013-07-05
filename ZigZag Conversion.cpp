class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string ret = "";
        int zigSize = 2 * nRows - 2;
        for (int i = 0 ; i < nRows ; i ++) {
            for (int j = i ; ; j += zigSize) {
                int index = j;
                if (index < s.length()) {
                    ret += s[index];
                } else {
                    break;
                }
                if (i == 0 || i == nRows - 1) continue;
                index = j + zigSize - i - i;
                if (index < s.length()) {
                    ret += s[index];
                } else {
                    break;
                }
            }
        }
        return ret;
    }
};