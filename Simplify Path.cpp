class Solution {
public:
    string simplifyPath(string path) {
        for (int i = 0 ; i < path.length() ; i ++) {
            if (path[i] == '/') {
                path[i] = ' ';
            }
        }
        stringstream ss(path);
        stack<string> st;
        while (ss >> path) {
            if (path == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (path != ".") {
                st.push(path);
            }
        }
        path = "";
        while (!st.empty()) {
            path = string("/") + st.top() + path;
            st.pop();
        }
        if (path == "") {
            path = "/";
        }
        return path;
    }
};