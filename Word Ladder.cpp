class Solution {
private:
    vector<string> words;
    vector<vector<int>> edge;
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
    int bfs(int start,int end) {
        dis = vector<int>(words.size() , -1);
        queue<int> que;
        que.push(start);
        dis[start] = 0;
        while (!que.empty()) {
            int u = que.front();
            if (u == end) {
                break;
            }
            que.pop();
            int d = dis[u] + 1;
            for (int i = 0 ; i < edge[u].size() ; i ++) {
                int v = edge[u][i];
                if (dis[v] == -1) {
                    dis[v] = d;
                    que.push(v);
                }
            }
        }
        return dis[end] + 1;
    }
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        build(dict);
        return bfs(ID[start] , ID[end]);
    }
};