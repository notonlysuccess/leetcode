class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        vector<int> left(n , 0);
        vector<int> right(n , 0);
        for (int i = 0 ; i < n ; i ++) {
            int index = i;
            while (index && height[index-1] >= height[i]) {
                index = left[index-1];
            }
            left[i] = index;
        }
        int ret = 0;
        for (int i = n - 1 ; i >= 0 ; i --) {
            int index = i;
            while (index != n - 1 && height[index+1] >= height[i]) {
                index = right[index+1];
            }
            right[i] = index;
            ret = max(ret , height[i] * (right[i] - left[i] + 1));
        }
        return ret;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> st;
        int ret = 0;
        for (int i = 0 ; i < height.size() ; ) {
            if (st.empty() || height[ st.top() ] < height[i]) {
                st.push(i++);
            } else {
                int last = st.top();
                st.pop();
                int length = st.empty() ? i : i - st.top() - 1;
                ret = max(ret , height[last] * length);
            }
        }
        return ret;
    }
};