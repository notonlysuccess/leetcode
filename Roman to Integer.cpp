class Solution {
public:
    int romanToInt(string s) {
        char roman[] = "IVXLCDM";
        int digit[] = {1,5,10,50,100,500,1000};
        int map[1<<8];
        for (int i = 0 ; i < 7 ; i ++) {
            map[ roman[i] ] = digit[i];
        }
        int ret = 0;
        for (int i = s.length() - 1 ; i >= 0 ; i --) {
            if (i == s.length() - 1 || map[ s[i] ] >= map[ s[i+1] ]) {
                ret += map[ s[i] ];
            } else {
                ret -= map[ s[i] ];
            }
        }
        return ret;
    }
};