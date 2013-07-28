class Solution {
private:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        int n = matrix.size();
        if (n == 0) {
            return ret;
        }
        int m = matrix[0].size();
        int sx = 0 , ex = n - 1 , sy = 0 , ey = m - 1;
        int nm = n * m;
        int x = 0 , y = 0 , d = 0;
        while (nm --) {
            ret.push_back(matrix[x][y]);
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (xx < sx || xx > ex || yy < sy || yy > ey) {
                if (d == 0) {
                    sx ++;
                } else if (d == 1) {
                    ey --;
                } else if (d == 2) {
                    ex --;
                } else {
                    sy ++;
                }
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