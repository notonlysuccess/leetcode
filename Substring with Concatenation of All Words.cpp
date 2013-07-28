class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int n = L.size();
        int l = L[0].length();
        unordered_map<string,int> have;
        for (int i = 0 ; i < n ; i ++) {
            have[ L[i] ] ++;
        }
        int count = have.size();
        for (int offset = 0 ; offset < l ; offset ++) {
            unordered_map<string,int> get;
            int cnt = 0;
            for (int i = offset ; i < S.length() ; i += l) {
                string sub = S.substr(i , l);
                if (have[sub]) {
                    if (++ get[sub] == have[sub]) {
                        cnt ++;
                    }
                }
                if (i >= n*l) { 
                    sub = S.substr(i - n*l , l);
                    if (have[sub] && --get[sub] < have[sub]) {
                        cnt --;
                    }
                }
                if (cnt == count) {
                    ret.push_back(i-n*l+l);
                }
            }
        }
        return ret;
    }
};