class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *ss = 0 , *pp = 0;
        while (*s) {
            if (*s == *p || *p == '?') {
                s ++ , p ++;
            } else if (*p == '*') {
                while (*p == '*') {
                    p ++;
                }
                if (!*p) {
                    return true;
                }
                ss = s;
                pp = p;
            } else if (ss) {
                s = ++ ss;
                p = pp;
            } else {
                return false;
            }
        }
        while (*p == '*') {
            p ++;
        }
        return !*s && !*p;
    }
};