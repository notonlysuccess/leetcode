class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		int n = matrix.size();
		if (n == 0) return 0;
		int m = matrix[0].size();
		vector<int> height(m + 1 , 0);
		int ret = 0;
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < m ; j ++) {
				if (matrix[i][j] == '0') {
					height[j] = 0;
				} else {
					height[j] ++;
				}
			}
			stack<int> st;
			for (int j = 0 ; j <= m ; ) {
				if (st.empty() || height[st.top()] <= height[j]) {
					st.push(j);
					j ++;
				} else {
					int val = height[st.top()];
					st.pop();
					ret = max(ret , val * (st.empty() ? j : j - st.top() - 1));
				}
			}
		}
		return ret;
	}
};