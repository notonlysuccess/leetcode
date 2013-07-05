class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int n = matrix.size();
        vector<int> ret;
        if (n == 0) {
            return ret;
        }
        int m = matrix[0].size();
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int x = 0 , y = 0;
        int d = 0;
        int total = n * m;
        int sx = 0 , ex = n - 1 , sy = 0 , ey = m - 1;
        while (total --) {
            ret.push_back(matrix[x][y]);
            x += dx[d];
            y += dy[d];
            if (x < sx || x > ex || y < sy || y > ey) {
                x -= dx[d];
                y -= dy[d];
                d ++;
                if (d == 4) {
                    d = 0;
                    ex --;
                    sy ++;
                    ey --;
                } else if (d == 1) {
                    sx ++;
                }
                x += dx[d];
                y += dy[d];
            }
        }
        return ret;
    }
};