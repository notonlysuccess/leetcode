class Solution {
private:
    int next[9][5] = {
    //space , -+ , . , e , digit
        {0,1,3,-1,2},
        {-1,-1,3,-1,2},
        {8,-1,4,5,2},
        {-1,-1,-1,-1,4},
        {8,-1,-1,5,4},
        {-1,6,-1,-1,7},
        {-1,-1,-1,-1,7},
        {8,-1,-1,-1,7},
        {8,-1,-1,-1,-1}
    };
public:
    bool isNumber(const char *s) {
        int state = 0;
        for ( ; *s ; s ++) {
            if (*s == ' ') {
                state = next[state][0];
            } else if (*s == '-' || *s == '+') {
                state = next[state][1];
            } else if (*s == '.') {
                state = next[state][2];
            } else if (*s == 'e') {
                state = next[state][3];
            } else if (isdigit(*s)) {
                state = next[state][4];
            } else {
                return false;
            }
            if (state == -1) {
                return false;
            }
        }
        return state == 2 || state == 4 || state == 7 || state == 8;
    }
};