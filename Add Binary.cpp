class Solution {
public:
	void change(string &a) {
		for (int i = 0 , j = a.length() - 1 ; i <= j ; i ++ , j --) {
			swap(a[i] , a[j]);
		}
	}
	char add(int s,bool &carry) {
		int sum = s + (int)carry;
		carry = sum > 1;
		return ('0' + sum % 2);
	}
	string addBinary(string a, string b) {
		change(a);
		change(b);
		int i = 0;
		string c = "";
		bool carry = false;
		for ( ; i < a.length() && i < b.length() ; i ++) {
			c += add(a[i] - '0' + b[i] - '0' , carry);
		}
		for ( ; i < a.length() ; i ++) {
			c += add(a[i] - '0' , carry);
		}
		for ( ; i < b.length() ; i ++) {
			c += add(b[i] - '0' , carry);
		}
		if (carry) {
			c += '1';
		}
		change(c);
		return c;
	}
};