class Solution {
public:
	string dfs(int num,int dig) {
		if (num == 0) return "";
		int n = num % 10;
		char one[] = "IXCM";
		char five[] = "VLD";
		string str = "";
		if (n <= 3) {
			while (n --) str += one[dig];
		} else if (n <= 5) {
			while (n ++ < 5) str += one[dig];
			str += five[dig];
		} else if (n <= 8) {
			str += five[dig];
			while (n -- > 5) str += one[dig];
		} else {
			str += one[dig];
			str += one[dig+1];
		}
		return dfs(num/10,dig+1) + str;
	}
	string intToRoman(int num) {
		return dfs(num,0);
	}
};