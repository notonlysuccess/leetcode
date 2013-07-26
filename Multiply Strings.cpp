class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string ret;
        int n = num1.size();
        int m = num2.size();
        vector<int> vec(n+m,0);
        for (int i = n - 1 ; i >= 0 ; i --) {
            for (int j = m - 1 ; j >= 0 ; j --) {
                vec[n-1-i+m-1-j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0 ; i < n + m ; i ++) {
            if (vec[i] >= 10) {
                vec[i+1] += vec[i] / 10;
                vec[i] %= 10;
            }
        }
        int last = n + m - 1;
        if (vec[last] == 0) last --;
        while (last >= 0) {
            ret += char(vec[last] + '0');
            last --;
        }
        return ret;
    }
};