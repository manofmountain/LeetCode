//17.96%
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.empty())
			return true;
		bool firstChr = word[0] >= 'A' && word[0] <= 'Z' ? true : false;
		bool secondChr(false);
		//Other chars need to be all upper or lower alphabets while firstChr is upper
		int cnt(0);
		for(int i = 1; i < word.size(); ++i){
			if(firstChr){
				if(word[i] >= 'A' && word[i] <= 'Z')
					++cnt;
			}else{
				if(word[i] >= 'A' && word[i] <= 'Z')
					return false;
			}
		}
		return cnt == 0 || cnt == word.size() - 1;		
    }
};

//3.93%
class Solution {
public:
    bool detectCapitalUse(string word) {
		int cnt(0);
		for(char c : word){
			if(c >= 'A' && c <= 'Z')
				++cnt;
		}
		return cnt == 0 || cnt == word.size() || cnt == 1 && word[0] >= 'A' && word[0] <= 'Z';		
    }
};

//Java by using regex
public boolean detectCapitalUse(String word) {
    return word.matches("[A-Z]+|[a-z]+|[A-Z][a-z]+");
}



