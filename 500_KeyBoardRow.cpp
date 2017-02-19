//1.85%
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        char row1[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
		char row2[] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
		char row3[] = {'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
		unordered_map<char, int> table;
		for(char c : row1){
			table[c] = 0;
			table[c - 'A' + 'a'] = 0;
		}
		for(char c : row2){
			table[c] = 1;
			table[c - 'A' + 'a'] = 1;
		}
		for(char c : row3){
			table[c] = 2;
			table[c - 'A' + 'a'] = 2;
		}
		vector<string> res;
		int currRow(-1);
		for(string word : words){
			currRow = table[word[0]];
			int j = 1;
			for(; j < word.size(); j++){
				int tempRow = table[word[j]];
				if(tempRow != currRow)
					break;
			}
			if(j == word.size())
				res.push_back(word);			
		}
		return res;
    }
};

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1 {'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
        unordered_set<char> row2 {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'}; 
        unordered_set<char> row3 { 'z', 'x', 'c', 'v', 'b' ,'n', 'm'};
        vector<unordered_set<char>> rows {row1, row2, row3};
        
        
        vector<string> validWords;
        for(int i=0; i<words.size(); ++i){
            int row=0;
            
            for(int k=0; k<3; ++k){
                if(rows[k].count((char)tolower(words[i][0])) > 0) row = k;
            }
            
            validWords.push_back(words[i]);
            for(int j=1; j<words[i].size(); ++j){
                if(rows[row].count((char)tolower(words[i][j])) == 0){
                    validWords.pop_back();
                    break;
                }
            }
            
        }
        return validWords;
    }
};