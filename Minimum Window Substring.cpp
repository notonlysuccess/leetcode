
class Solution {
public:
    bool ok(int length , string &S,string &ret,int t[],int total) {
        int s[1<<7];
        memset(s , 0 , sizeof(s));
        int sum = 0;
        for (int i = 0 ; i < length ; i ++) {
            s[ S[i] ] ++;
            if (s[ S[i] ] == t[ S[i] ]) {
                sum ++;
            }
        }
        if (sum == total) {
            ret = S.substr(0 , length);
            return true;
        }
        for (int i = length ; i < S.size() ; i ++) {
            s[ S[i] ] ++;
            if (s[ S[i] ] == t[ S[i] ]) {
                sum ++;
            }
            if (s[ S[i-length] ] == t[ S[i-length] ]) {
                sum --;
            }
            s[ S[i-length] ] --;
            if (sum == total) {
                ret = S.substr(i - length + 1 , length);
                return true;
            }
        }
        return false;
    }
    string minWindow(string S, string T) {
        int t[1<<7];
        memset(t , 0 , sizeof(t));
        int total = 0;
        for (int i = 0 ; i < T.size() ; i ++) {
            if (t[ T[i] ] == 0) total ++;
            t[ T[i] ] ++;
        }
        int lo = T.size() , hi = S.size();
        string ret = "";
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (ok(mid , S , ret , t , total)) hi = mid - 1;
            else lo = mid + 1;
        }
        return ret;
    }
};
