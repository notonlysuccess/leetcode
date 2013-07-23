class Solution {
public:
    int climbStairs(int n) {
        vector<int> fib(n+1,1);
        for (int i = 2 ; i <= n ; i ++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }
};