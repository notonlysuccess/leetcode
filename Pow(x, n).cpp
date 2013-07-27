class Solution {
public:
    double pow(double x, int n) {
        if (n > 0) {
            return pow(1/x , -n);
        }
        double ret = 1;
        for ( ; n ; n /= 2) {
            if (n&1) ret *= x;
            x *= x;
        }
        return 1/ret;
    }
};