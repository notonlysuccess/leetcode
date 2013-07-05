class Solution {
public:
    double pow(double x, int n) {
        if (n > 0) {
            return pow(1/x , -n);
        }
        double ret = 1;
        while (n) {
            if (n&1) ret *= x;
            x *= x;
            n /= 2;
        }
        return 1/ret;
    }
};