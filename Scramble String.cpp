class Solution {
private:
    vector<vector<vector<char> > > dp;
    string s , t;
    bool dfs(int i,int j,int n) {
        if (dp[i][j][n] != 2) {
            return dp[i][j][n];
        }
        if (n == 1) {
            return s[i] == t[j];
        }
        for (int k = 1 ; k < n ; k ++) {
            if ((dfs(i , j , k) && dfs(i + k , j + k , n - k))
             || (dfs(i + n - k , j , k) && dfs(i , j + k , n - k))) {
                 return dp[i][j][n] = true;
             }
        }
        return dp[i][j][n] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        s = s1, t = s2;
        int n = s.length();
        dp.assign(n , vector<vector<char>>(n , vector<char>(n+1 , 2)));
        return dfs(0 , 0 , n);
    }
};