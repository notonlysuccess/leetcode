class Solution {
public:
	vector<int> grayCode(int n) {
		vector<bool> hash(1<<n , false);
		vector<int> ret;
		int step = 0;
		int m = 1<<n;
		int now = 0;
		while (step < m) {
			ret.push_back(now);
			hash[now] = true;
			step ++;
			for (int i = 0 ; i < n ; i ++) {
				int next = now ^ (1<<i);
				if (hash[next]) continue;
				now = next;
				break;
			}
		}
		return ret;
	}
};