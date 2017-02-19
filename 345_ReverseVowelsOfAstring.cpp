class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels;
		const int vowelNum = 10;
		char vowelArray[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
		vowels.insert(vowelArray, vowelArray + vowelNum);
		int i(0), j(s.size() - 1);
		while(i < j){
			while(i < j && vowels.find(s[i]) == vowels.end())
				i++;
			while(i < j && vowels.find(s[j]) == vowels.end())
				j--;
			if(i < j){
				swap(s[i], s[j]);
				i++;
				j--;
			}
		}
		return s;
    }
};

//A super clean solution from LeetCode
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};