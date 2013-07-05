class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0) return 0;
        char roman[] = "IVXLCDM";
        int digit[] = {1,5,10,50,100,500,1000};
        int rank[127];
        for (int i = 0 ; i < 7 ; i ++) {
            rank[ roman[i] ] = digit[i];
        }
        int n = s.length();
        int ret = rank[ s[n-1] ];
        for (int i = n - 2 ; i >= 0 ; i --) {
            if (rank[ s[i] ] >= rank[ s[i+1] ]) {
                ret += rank[ s[i] ];
            } else {
                ret -= rank[ s[i] ];
            }
        }
        return ret;
    }
};