class Solution {
private:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ret(n , vector<int>(n,0));
        int x = 0 , y = 0 , d = 0;
        int nn = n * n;
        for (int i = 1 ; i <= nn ; i ++) {
            ret[x][y] = i;
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (xx < 0 || xx == n || yy < 0 || yy == n || ret[xx][yy]) {
                d = (d + 1)%4;
                xx = x + dx[d];
                yy = y + dy[d];
            }
            x = xx;
            y = yy;
        }
        return ret;
    }
};