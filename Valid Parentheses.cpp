/*
O(n^3) DP
*/
class Solution {
public:
    bool ok(char a,char b) {
        if (a == '(' && b == ')') return true;
        if (a == '[' && b == ']') return true;
        if (a == '{' && b == '}') return true;
        return false;
    }
    bool isValid(string s) {
        int n = s.length();
        if (n == 0) return true;
        if (n&1) return false;
        vector< vector<bool> > vaild(n , vector<bool>(n+1 , true));
        for (int l = 2 ; l <= n ; l += 2) {
            for (int i = 0 ; i + l <= n ; i ++) {
                vaild[i][l] = false;
                if (ok(s[i],s[i+l-1]) && vaild[i+1][l-2]) {
                    vaild[i][l] = true;
                    continue;
                }
                for (int k = 2 ; k < l ; k += 2) {
                    if (vaild[i][k] && vaild[i+k][l-k]) {
                        vaild[i][l] = true;
                        break;
                    }
                }
            }
        }
        return vaild[0][n];
    }
};

/*
O(n) stack
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0 ; i < s.length() ; i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (st.empty()) {
                return false;
            } else {
                if (st.top() != s[i] - 1 && st.top() != s[i] - 2) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};


