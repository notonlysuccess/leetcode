class Solution {
private:
    int n , m;
    void dfs(int x, int y, vector<vector<char> > &board) {
        if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O') {
            board[x][y] = '#';
            dfs(x+1,y,board);
            dfs(x-1,y,board);
            dfs(x,y-1,board);
            dfs(x,y+1,board);
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        n = board.size();
        if (n == 0) {
            return ;
        }
        m = board[0].size();
        for (int i = 0 ; i < n ; i ++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if (board[i][m-1] == 'O') {
                dfs(i, m - 1, board);
            }
        }
        for (int j = 0 ; j < m ; j ++) {
            if (board[0][j] == 'O') {
                dfs(0, j, board);
            }
            if (board[n-1][j] == 'O') {
                dfs(n-1, j, board);
            }
        }
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                board[i][j] = board[i][j] == '#' ? 'O' : 'X';
            }
        }
    }
};