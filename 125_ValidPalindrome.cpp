//38.9%
class Solution {
public:
    bool isPalindrome(string s) {
        int l(0), r(s.size() - 1);
		while(l < r){
			while(l < r && !isalnum(s[l]))
				l++;
			while(l < r && !isalnum(s[r]))
				r--;
			if(l < r){
				if(isalpha(s[r]) && isalpha(s[l])){
					if(tolower(s[r]) != tolower(s[l]))
						return false;
				}
				else if(s[r] != s[l])
					return false;
			}
			l++;
			r--;
		}
		return true;
    }
	
};

bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }
    
    return true;
}

//I love this way better, it can be applied to 'Quick sorting'
bool isPalindrome(string s) {
	int start=0, end=s.length()-1;
	while(start<end) {
		if (!isalnum(s[start])) start++;
		else if (!isalnum(s[end])) end--;
		else {
			if (tolower(s[start++])!=tolower(s[end--])) return false;
		}
	}
	return true;
}