class Solution {
private:
    bool hash[27][10];
public:
    bool dfs(int i,int j,vector<vector<char> > &board) {
        if (j == 9) {
            j = 0;
            i ++;
        }
        if (i == 9) {
            return true;
        }
        if (board[i][j] != '.') {
            return dfs(i,j+1,board);
        }
        for (int d = 1; d <= 9 ; d++) {
            if (hash[i][d] ||
                hash[j+9][d] ||
                hash[i/3*3+j/3+18][d]) continue;
            board[i][j] = d + '0';
            hash[i][d] = hash[j+9][d] = hash[i/3*3+j/3+18][d] = true;
            if (dfs(i,j+1,board)) {
                return true;
            }
            hash[i][d] = hash[j+9][d] = hash[i/3*3+j/3+18][d] = false;
        }
        board[i][j] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        memset(hash , false , sizeof(hash));
        for (int i = 0 ; i < 9 ; i ++) {
            for (int j = 0 ; j < 9 ; j ++) {
                if (board[i][j] == '.') continue;
                hash[i][ board[i][j] - '0' ] = true;
                hash[j+9][ board[i][j] - '0' ] = true;
                hash[i/3*3+j/3+18][ board[i][j] - '0' ] = true;
            }
        }
        dfs(0 , 0 , board);
    }
};