class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n = strlen(needle);
        if (n == 0) {
            return haystack;
        }
        vector<int> fail(n , -1);
        for (int i = 1 , j = -1; i < n ; i ++) {
            while (j >= 0 && needle[j+1] != needle[i]) {
                j = fail[j];
            }
            if (needle[j+1] == needle[i]) {
                fail[i] = ++ j;
            }
        }
        for (int i = 0 , j = -1; haystack[i] ; i ++) {
            while (j >= 0 && needle[j+1] != haystack[i]) {
                j = fail[j];
            }
            if (needle[j+1] == haystack[i]) {
                j ++;
                if (j + 1 == n) {
                    return haystack + i - n + 1;
                }
            }
        }
        return NULL;
    }
};