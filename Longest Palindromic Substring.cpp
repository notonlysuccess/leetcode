class Solution { 
public:     
	string longestPalindrome(string s) {         
		int n = s.length();         
		string ans = "";         
		for (int i = 0 ; i < n ; i ++) {             
			for (int j = 0 ; i - j >= 0 && i + j < n && s[i-j] == s[i+j]; j ++) {                 
				if (j*2 + 1 > ans.size()) {                     
					ans = s.substr(i-j,j*2+1);                 
				}             
			}             
			for (int j = 0 ; i - j >= 0 && i + j + 1 < n && s[i-j] == s[i+j+1]; j ++) {                 
				if (j*2 + 2 > ans.size()) {                     
					ans = s.substr(i-j,j*2+2);                 
				}             
			}         
		}         
		return ans;     
	} 
};