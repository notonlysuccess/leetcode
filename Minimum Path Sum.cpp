class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (i && j) {
                    grid[i][j] += min(grid[i-1][j] , grid[i][j-1]);
                } else if (i) {
                    grid[i][j] += grid[i-1][j];
                } else if (j) {
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
        return grid[n-1][m-1];
    }
};