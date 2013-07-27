class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen(s);
        int m = strlen(p);
        vector<vector<bool>> dp(n+1 , vector<bool>(m+1,false));
        dp[0][0] = true;
        for (int i = 0 ; i <= n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (dp[i][j]) {
                    if (i < n && (s[i] == p[j] || '.' == p[j])) {
                        dp[i+1][j+1] = true;
                    }
                    if (j + 1 < m && p[j+1] == '*') {
                        dp[i][j+2] = true;
                        for (int k = i ; k < n && (s[k] == p[j] || '.' == p[j]); k ++) {
                            dp[k+1][j+2] = true;
                        }
                    }
                }
            }
        }
        return dp[n][m];
    } 
};