class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int> > dp(n+1 , vector<int>(m+1,0));
        dp[0][0] = 1;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (i) {
                    dp[i][j] += dp[i-1][j];
                }
                if (j) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};