class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *beginS = NULL , *beginP = NULL;
        while (*s) {
            if (*s == *p || *p == '?') {
                s ++;
                p ++;
            } else if (*p == '*') {
                while (*p == '*') {
                    p ++;
                }
                if (!*p) {
                    return true;
                }
                beginS = s;
                beginP = p;
            } else if (beginP) {
                s = ++beginS;
                p = beginP;
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