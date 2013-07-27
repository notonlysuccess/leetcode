class Solution {
private:
    vector<vector<int> > ret;
    vector<int> per;
    vector<bool> used;
    void dfs(int id,vector<int> &num) {
        if (id == num.size()) {
            ret.push_back(per);
            return ;
        }
        for (int i = 0 ; i < num.size() ; i ++) {
            if (!used[i] && (i == 0 || num[i] != num[i-1] || used[i-1])) {
                used[i] = true;
                per[id] = num[i];
                dfs(id + 1 , num);
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin() , num.end());
        ret.clear();
        per.resize(num.size());
        used.resize(num.size());
        dfs(0 , num);
        return ret;
    }
};