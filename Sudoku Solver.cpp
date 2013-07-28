class Solution {
private:
    int row[9];
    int column[9];
    int block[9];
    bool dfs(int x,int y,vector<vector<char> > &board) {
        if (y == 9) {
            y = 0;
            x ++;
        }
        if (x == 9) {
            return true;
        }
        if (board[x][y] != '.') {
            return dfs(x , y + 1 , board);
        }
        for (int i = 1 ; i <= 9 ; i ++) {
            int val = 1 << i;
            if ((row[x] & val) || (column[y] & val) || (block[x/3*3+y/3] & val)) {
                continue;
            }
            board[x][y] = i + '0';
            row[x] |= val;
            column[y] |= val;
            block[x/3*3+y/3] |= val;
            if (dfs(x, y + 1, board)) {
                return true;
            }
            row[x] ^= val;
            column[y] ^= val;
            block[x/3*3+y/3] ^= val;
        }
        board[x][y] = '.';
        return false;
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        memset(row , 0 , sizeof(row));
        memset(column , 0 , sizeof(column));
        memset(block , 0 , sizeof(block));
        for (int i = 0 ; i < 9 ; i ++) {
            for (int j = 0 ; j < 9 ; j ++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int val = 1 << (board[i][j] - '0');
                row[i] |= val;
                column[j] |= val;
                block[i/3*3+j/3] |= val;
            }
        }
        dfs(0 , 0 , board);
    }
};