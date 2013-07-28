class Solution {
public:
    int atoi(const char *str) {
        int ret = 0;
        int sign = 1;
        for ( ; *str == ' '; str ++);
        if (*str == '-') {
            sign = -1;
            str ++;
        } else if (*str == '+') {
            str ++;
        }
        for ( ; isdigit(*str) ; str ++) {
            if ((ret == 214748364 && *str - '0' > 7) || (ret > 214748364)) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            ret = ret * 10 + *str - '0';
        }
        return sign == -1 ? -ret : ret;
    }
};