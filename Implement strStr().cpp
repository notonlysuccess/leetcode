class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!needle[0]) return haystack;
		int n = 0;
		for ( ; needle[n] ; n ++);
		vector<int> fail(n , -1);
		for (int i = 1 , j = -1 ; i < n ; i ++) {
			while (j >= 0 && needle[j+1] != needle[i]) {
				j = fail[j];
			}
			if (needle[j+1] == needle[i]) {
				fail[i] = j + 1;
				j ++;
			}
		}
		for (int i = 0 , j = 0 ; haystack[i] ; i ++) {
			while (j && needle[j] != haystack[i]) {
				j = fail[j-1] + 1;
			}
			if (haystack[i] == needle[j]) {
				j ++;
				if (j == n) {
					return haystack + i - n + 1;
				}
			}
		}
		return NULL;
	}
};