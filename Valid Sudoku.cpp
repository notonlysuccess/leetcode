class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool hash[27][10];
        memset(hash , false , sizeof(hash));
        for (int i = 0 ; i < 9 ; i ++) {
            for (int j = 0 ; j < 9 ; j ++) {
                if (board[i][j] == '.') continue;
                int d = board[i][j] - '0';
                if (hash[i][d] ||
                    hash[j+9][d] ||
                    hash[i/3*3+j/3+18][d]) {
                        return false;
                    }
                hash[i][d] = true;
                hash[j+9][d] = true;
                hash[i/3*3+j/3+18][d] = true;
            }
        }
        return true;
    }
};