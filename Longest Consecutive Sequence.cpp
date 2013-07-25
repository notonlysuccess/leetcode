class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> dig;
        for (int i = 0 ; i < num.size() ; i ++) {
            dig.insert(num[i]);
        }
        int ret = 0;
        for (int i = 0 ; i < num.size() ; i ++) {
            if (dig.find(num[i]) != dig.end()) {
                dig.erase(num[i]);
                int lo = num[i] - 1;
                while (dig.find(lo) != dig.end()) {
                    dig.erase(lo--);
                }
                int hi = num[i] + 1;
                while (dig.find(hi) != dig.end()) {
                    dig.erase(hi++);
                }
                ret = max(ret , hi - lo - 1);
            }
        }
        return ret;
    }
};