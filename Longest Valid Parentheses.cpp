class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ret = 0 , last = -1;
        for (int i = 0 ; i < s.length() ; i ++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (st.empty()){
                last = i;
            } else {
                st.pop();
                if (st.empty()) {
                    ret = max(ret , i - last);
                } else {
                    ret = max(ret , i - st.top());
                }
            }
        }
        return ret;
    }
};