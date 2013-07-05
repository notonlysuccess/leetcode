class Solution {
public:
    string itoa(int count) {
		string ret = "";
		while (count) {
			ret += (char)(count % 10) + '0';
			count /= 10;
		}
		return ret;
	}
	string gen(string &str) {
		int count = 0;
		int number = -1;
		string ret = "";
		for (int i = 0 ; i < str.length() ; i ++) {
			if (str[i] - '0' == number) {
				count ++;
			} else {
				if (i != 0) {
					ret += itoa(count);
					ret += char(number + '0');
				}
				number = str[i] - '0';
				count = 1;
			}
		}
		ret += itoa(count);
		ret += char(number + '0');
		return ret;
	}
	string countAndSay(int n) {
		string str = "1";
        n --;
		while (n --) {
			str = gen(str);
		}
		return str;
	}
};