class Solution {
public:
    void reverse(string &str) {
        for (int i = 0 , j = str.length() - 1;i < j; i ++ , j --) {
            swap(str[i] , str[j]);
        }
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string ret;
        int n = num1.size();
        int m = num2.size();
        reverse(num1);
        reverse(num2);
        vector<int> vec(n+m+1,0);
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                vec[i+j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0 ; i < n + m ; i ++) {
            if (vec[i] >= 10) {
                vec[i+1] += vec[i] / 10;
                vec[i] %= 10;
            }
        }
        int last = n + m;
        while (vec[last] == 0) last --;
        while (last >= 0) {
            ret += char(vec[last] + '0');
            last --;
        }
        return ret;
    }
};