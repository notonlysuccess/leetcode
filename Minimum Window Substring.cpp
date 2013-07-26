class Solution {
public:
    string minWindow(string S, string T) {
        int count[1<<8] = {0};
        bool hash[1<<8] = {false};
        int total = 0;
        for (int i = 0 ; i < T.length() ; i ++) {
            if (!hash[ T[i] ]) {
                total ++;
            }
            hash[ T[i] ] = true;
            count[ T[i] ] ++;
        }
        queue<int> que;
        int minret = INT_MAX , start = -1 , sum = 0;
        for (int i = 0 ; i < S.length() ; i ++) {
            count[ S[i] ] --;
            if (hash[ S[i] ]) {
                que.push(i);
                if (count[ S[i] ] == 0) {
                    sum ++;
                }
            }
            while (!que.empty() && count[ S[que.front()] ] < 0) {
                count[ S[que.front()] ] ++;
                que.pop();
            }
            if (sum == total) {
                if (i - que.front() + 1 < minret) {
                    minret = i - que.front() + 1;
                    start = que.front();
                }
            }
        }
        if (start == -1) {
            return "";
        } else {
            return S.substr(start , minret);
        }
    }
};


/*
 * best method
 */
class Solution {
public:
    string minWindow(string S, string T) {
        int need[1<<8] = {0};
        int has[1<<8] = {0};
        int total = 0;
        for (int i = 0 ; i < T.length() ; i ++) {
            if (need[ T[i] ] == 0) {
                total ++;
            }
            need[ T[i] ] ++;
        }
        int head = 0 , start = -1 , length = INT_MAX;
        for (int tail = 0 ; tail < S.length() ; tail ++) {
            has[ S[tail] ] ++;
            if (has[ S[tail] ] == need[ S[tail] ]) {
                total --;
            }
            while (head < tail && has[ S[head] ] > need[ S[head] ]) {
                has[ S[head++] ] --;
            }
            if (total == 0 && tail - head + 1 < length) {
                length = tail - head + 1;
                start = head;
            }
        }
        return start == -1 ? "" : S.substr(start , length);
    }
};