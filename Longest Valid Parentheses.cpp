class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		int ret = 0;
		for (int i = 0 ; i < s.length() ; i ++) {
			if (s[i] == '(') {
				st.push(i);
			} else if (!st.empty()) {
				ret = max(ret , i - st.top() + 1);
				if (i + 1 == s.length() || s[i+1] == ')') {
					st.pop();
				} else {
					i ++;
				}
			}
		}
		return ret;
	}
};