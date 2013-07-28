class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 1;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        row = 0;
                    } else {
                        matrix[i][0] = 0;
                    }
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1 ; i < n ; i ++) {
            if (matrix[i][0] == 0) {
                for (int j = 0 ; j < m ; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0 ; j < m ; j ++) {
            if (matrix[0][j] == 0) {
                for (int i = 0 ; i < n ; i ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row == 0) {
            for (int j = 0 ; j < m ; j ++) {
                matrix[0][j] = 0;
            }
        }
    }
};