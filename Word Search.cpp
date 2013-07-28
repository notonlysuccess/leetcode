class Solution {
private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool dfs(int x,int y,int k,string &word,vector<vector<char> > &board) {
        if (k == word.length()) {
            return true;
        }
        if (x < 0 || x == board.size() || y < 0 || y == board[0].size() || board[x][y] != word[k]) {
            return false;
        }
        char ch = board[x][y];
        board[x][y] = '#';
        for (int d = 0 ; d < 4 ; d ++) {
            if (dfs(x+dx[d] , y+dy[d] , k+1 , word , board)) {
                return true;
            }
        }
        board[x][y] = ch;
        return false;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        for (int i = 0 ; i < board.size() ; i ++) {
            for (int j = 0 ; j < board[i].size() ; j ++) {
                if (dfs(i , j , 0 , word , board)) {
                    return true;
                }
            }
        }
        return false;
    }
};