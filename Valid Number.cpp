class Solution {
public:
    bool isNumber(const char *s) {
        bool dot = false;
        bool e = false;
        int num = 0;
        int count = 0;
        for (int i = 0 ; s[i] ; i ++) {
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
                count ++;
                if (count == 2) return false;
            }
            if (s[i] == '+' || s[i] == '-') {
                if (i && s[i-1] != ' ' && s[i-1] != 'e') return false;
            } else if (s[i] == '.') {
                if (dot) return false;
                if (e) return false;
                dot = true;
            } else if (s[i] == 'e') {
                if (num == 0) return false;
                if (e) return false;
                e = true;
                num = 0;
            } else if (isdigit(s[i])) {
                if (i == 0 || !isdigit(s[i-1])) {
                    num ++;
                }
            } else if (s[i] != ' ') {
                return false;
            }
        }
        return num >= 1;
    }
};