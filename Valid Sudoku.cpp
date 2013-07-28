class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row[9];
        int column[9];
        int block[9];
        memset(row , 0 , sizeof(row));
        memset(column , 0 , sizeof(column));
        memset(block , 0 , sizeof(block));
        for (int i = 0 ; i < 9 ; i ++) {
            for (int j = 0 ; j < 9 ; j ++) {
                if (board[i][j] != '.') {
                    int val = 1 << (board[i][j] - '0');
                    if ((row[i] & val) || (column[j] & val) || (block[i/3*3+j/3] & val)) {
                        return false;
                    }
                    row[i] |= val;
                    column[j] |= val;
                    block[i/3*3+j/3] |= val;
                }
            }
        }
        return true;
    }
};