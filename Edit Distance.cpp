class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int> > dp(n+1,vector<int>(m+1,m+n));
        dp[0][0] = 0;
        for (int i = 0 ; i <= n ; i ++) {
            for (int j = 0 ; j <= m ; j ++) {
                if (i < n && j < m) {
                    if (word1[i] == word2[j]) {//same
                        dp[i+1][j+1] = min(dp[i+1][j+1] , dp[i][j]);
                    } else {//replace
                        dp[i+1][j+1] = min(dp[i+1][j+1] , dp[i][j] + 1);
                    }
                }
                if (i < n) {//delete
                    dp[i+1][j] = min(dp[i+1][j] , dp[i][j] + 1);
                }
                if (j < m) {//insert
                    dp[i][j+1] = min(dp[i][j+1] , dp[i][j] + 1);
                }
            }
        }
        return dp[n][m];
    }
};