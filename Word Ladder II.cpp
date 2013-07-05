class Solution {
private:
    vector<string> words;
    vector<vector<int>> edge;
    vector<vector<int>> pre;
    unordered_map<string,int> ID;
    vector<int> dis;
    void build(unordered_set<string> &dict) {
        words.clear();
        ID.clear();
        for (auto iter = dict.begin() ; iter != dict.end() ; iter ++) {
            ID[ *iter ] = words.size();
            words.push_back(*iter);
        }
        edge.clear();
        edge.resize(words.size());
        for (int i = 0 ; i < words.size() ; i ++) {
            for (int j = 0 ; j < words[i].length() ; j ++) {
                char buf = words[i][j];
                for (char ch = 'a' ; ch <= 'z' ; ch ++) {
                    if (ch == buf) continue;
                    words[i][j] = ch;
                    auto iter = ID.find(words[i]);
                    if (iter != ID.end()) {
                        edge[i].push_back(iter->second);
                    }
                }
                words[i][j] = buf;
            }
        }
    }
    void bfs(int start,int end) {
        dis = vector<int>(words.size() , -1);
        pre.clear();
        pre.resize(words.size());
        queue<int> que;
        que.push(end);
        dis[end] = 0;
        while (!que.empty()) {
            int u = que.front();
            if (u == start);
            que.pop();
            int d = dis[u] + 1;
            for (int i = 0 ; i < edge[u].size() ; i ++) {
                int v = edge[u][i];
                if (dis[v] == -1) {
                    dis[v] = d;
                    pre[v].push_back(u);
                    que.push(v);
                } else if (dis[v] == d) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    void gen(int start,int end,vector<vector<string>> &ret,vector<int> &temp) {
        temp.push_back(start);
        if (start == end) {
            ret.push_back(vector<string>());
            for (int i = 0 ; i < temp.size() ; i ++) {
                ret.back().push_back(words[ temp[i] ]);
            }
        } else {
          for (int i = 0 ; i < pre[start].size() ; i ++) {
              gen(pre[start][i] , end , ret , temp);
            }
        }
        temp.pop_back();
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ret;
        dict.insert(start);
        dict.insert(end);
        build(dict);
        bfs(ID[start] , ID[end]);
        vector<int> temp;
        gen(ID[start] , ID[end] , ret , temp);
        return ret;
    }
};