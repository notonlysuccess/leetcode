class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();
		vector<vector<int> > dp(n+1 , vector<int>(m+1,n+m));
		dp[0][0] = 0;
		for (int i = 0 ; i <= n ; i ++) {
			for (int j = 0 ; j <= m ; j ++) {
				if (j != m) {
					if (i != n) {
						if (word1[i] == word2[j]) {
							dp[i+1][j+1] = min(dp[i+1][j+1] , dp[i][j]);
						} else {
							dp[i+1][j+1] = min(dp[i+1][j+1] , dp[i][j] + 1);
						}
					}
					dp[i][j+1] = min(dp[i][j+1] , dp[i][j] + 1);
				}
				if (i != n) {
					dp[i+1][j] = min(dp[i+1][j] , dp[i][j] + 1);
				}
			}
		}
		return dp[n][m];
	}
};