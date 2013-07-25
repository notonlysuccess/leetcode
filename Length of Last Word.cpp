class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;
        while (*s) {
            if (*(s++) != ' ') {
                length ++;
            } else if (*s && *s != ' ') {
                length = 0;
            }
        }
        return length;
    }
};