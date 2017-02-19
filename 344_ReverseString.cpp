//33.88%
class Solution {
public:
    string reverseString(string s) {
        int size(s.size());
		int front(0), back(size - 1);
		while(front < back){
			swap(s[front], s[back]);
			front++;
			back--;
		}
		return s;
    }
};

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
        
        return s;
    }
};