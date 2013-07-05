class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int n = s1.size() , m = s2.size() , k = s3.size();
		if (n + m != k) return false;
		vector<vector<int> > dp(n+1 , vector<int>(m+1 , 0));
		for (int i = 0 ; i <= n ; i ++) {
			for (int j = 0 ; j <= m ; j ++) {
				if (i < n && s1[i] == s3[ dp[i][j] ]) {
					dp[i+1][j] = max(dp[i+1][j] , dp[i][j] + 1);
				}
				if (j < m && s2[j] == s3[ dp[i][j] ]) {
					dp[i][j+1] = max(dp[i][j+1] , dp[i][j] + 1);
				}
			}
		}
		return dp[n][m] == k;
	}
};