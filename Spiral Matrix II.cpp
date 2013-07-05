class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ret(n , vector<int>(n,0));
        int total = n * n;
        int x = 0 , y = 0 , d = 0;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for (int i = 1 ; i <= total ; i ++) {
            ret[x][y] = i;
            x += dx[d];
            y += dy[d];
            if (x < 0 || x == n || y < 0 || y == n || ret[x][y]) {
                x -= dx[d];
                y -= dy[d];
                d ++;
                if (d == 4) {
                    d = 0;
                }
                x += dx[d];
                y += dy[d];
            }
        }
        return ret;
    }
};