class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (int i = 0 ; i < s.length() ; i ++) {
            t += s[i];
            t += '#';
        }
        vector<int> p(t.length() , 1);
        int center = 0 , mx = 0 , c = 0 , r = 0;
        for (int i = 1 ; i < t.length() ; i ++) {
            p[i] = i < mx ? min(p[center*2-i] , mx - i) : 1;
            while (i - p[i] >= 0 && i + p[i] < t.length() && t[i-p[i]] == t[i+p[i]]) {
                p[i] ++;
            }
            if (i + p[i] > mx) {
                mx = i + p[i];
                center = i;
            }
            if (p[i] > r) {
                r = p[i];
                c = i;
            }
        }
        string ret = "";
        for (int i = c - r + 1 ; i <= c + r - 1 ; i ++) {
            if (t[i] != '#') {
                ret += t[i];
            }
        }
        return ret;
    }
};