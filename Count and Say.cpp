class Solution {
private:
    string itoa(int count) {
        string ret;
        for ( ; count ; count /= 10) {
            ret += (count % 10) + '0';
        }
        reverse(ret.begin() , ret.end());
        return ret;
    }
public:
    string countAndSay(int n) {
        string str[2];
        str[0] = "1";
        int S = 0 , T;
        while (-- n) {
            T = 1^S;
            str[T] = "";
            for (int i = 0 ; i < str[S].length() ;) {
                int j = i;
                for ( ; j < str[S].length() && str[S][i] == str[S][j] ; j ++);
                str[T] += itoa(j - i) + str[S][i];
                i = j;
            }
            S = T;
        }
        return str[S];
    }
};