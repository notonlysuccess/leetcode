class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_map<int,int> mp;
		vector<bool> visited(num.size() , false);
		for (int i = 0 ; i < num.size() ; i ++) {
			mp[ num[i] ] = i;
		}
		int ret = 0;
		for (int i = 0 ; i < num.size() ; i ++) {
			if (visited[i]) continue;
			visited[i] = true;
			int count = 1;
			int val = num[i];
			unordered_map<int,int>::iterator iter = mp.find(--val);
			while (iter != mp.end()) {
				visited[iter->second] = true;
				count ++;
				iter = mp.find(--val);
			}
			val = num[i];
			iter = mp.find(++val);
			while (iter != mp.end()) {
				visited[iter->second] = true;
				count ++;
				iter = mp.find(++val);
			}
			ret = max(ret , count);
		}
		return ret;
	}
};