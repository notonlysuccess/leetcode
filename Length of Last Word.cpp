class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int last = 0;
		int count = 0;
		for (int i = 0 ; s[i] ; i ++) {
			if (s[i] == ' ') {
				if (count) {
					last = count;
				}
				count = 0;
			} else {
				count ++;
			}
		}
		if (count) last = count;
		return last;
	}
};