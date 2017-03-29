//20.33%
class WordNode{
	public:
		WordNode():next(26), isWord(false){

		}
		//bool isWord;
		bool search(string word){
			if(word.empty())
				return false;
			if(word[0] == '.'){
				for(auto node : next){
					if(node){
						if(word.size() == 1){
							if(node -> isWord)
								return true;
						}else if(node -> search(word.substr(1)))
							return true;
					}
				}
				return false;
			}
			if(!next[word[0] - 'a'])
				return false;
			if(word.size() == 1)
				if(next[word[0] - 'a'] -> isWord)
					return true;
				else
					return false;
			return next[word[0] - 'a'] -> search(word.substr(1));	
		}
		void addWord(string word){
			if(word.empty())
				return;
			if(!next[word[0] - 'a'])
				next[word[0] - 'a'] = new WordNode;
			if(word.size() == 1)
				next[word[0] - 'a'] -> isWord = true;
			else
				next[word[0] - 'a'] -> addWord(word.substr(1));
		}
	private:
		bool isWord;
		vector<WordNode *> next;			
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary():root(new WordNode) {
   
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root -> addWord(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return root -> search(word);
    }
private:
	WordNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

//77.9%
struct WordNode{
		WordNode():next(26), isWord(false){

		}
		bool isWord;
		vector<WordNode *> next;	
		bool search(string word){
			if(word.empty())
				return false;
			if(word[0] != '.'){
				if(!next[word[0] - 'a'])
					return false;
				else if(word.size() == 1){
					if(next[word[0] - 'a'] -> isWord)
						return true;
					else
						return false;
				}else
					return next[word[0] - 'a'] -> search(word.substr(1));
			}else{
				for(int i = 0; i < 26; ++i){
					if(next[i]){
						if(word.size() == 1){
							if(next[i] -> isWord)
								return true;
						}else{
							if(next[i] -> search(word.substr(1)))
								return true;
						}
					}
				}
				return false;
			}
		}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary():root(new WordNode) {
   
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if(word.empty())
			return;
		WordNode *curr(root);
		for(auto c : word){
			if(!curr -> next[c - 'a'])
				curr -> next[c - 'a'] = new WordNode;
			curr = curr -> next[c - 'a'];
		}
		curr -> isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.empty())
			return true;
		WordNode *curr(root);
		for(int i = 0; i < word.size(); ++i){
			char c = word[i];
			if(c != '.'){
				if(!curr -> next[c - 'a'])
					return false;
				curr = curr -> next[c - 'a'];
			}else{
				for(auto node : curr -> next){
					if(node){
						if(i == word.size() - 1){
							if(node -> isWord)
								return true;
						}else{
						if(node -> search(word.substr(i + 1)))
							return true;
						}
					}
				}
				return false;
			}	
		}
		return curr -> isWord;
    }
private:
	WordNode *root;
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
 
 
//A good one from LeetCode and didn't use lots of repetitive codes
 class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(): isKey(false) {
        memset(children, NULL, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* run = root;
        for (char c : word) {
            if (!(run -> children[c - 'a'])) 
                run -> children[c - 'a'] = new TrieNode();
            run = run -> children[c - 'a'];
        }
        run -> isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word.c_str(), root);
    }

private:
    TrieNode* root;

    bool query(const char* word, TrieNode* node) {
        TrieNode* run = node;
        for (int i = 0; word[i]; i++) {
            if (run && word[i] != '.')
                run = run -> children[word[i] - 'a'];
            else if (run && word[i] == '.') { 
                TrieNode* tmp = run;
                for (int j = 0; j < 26; j++) {
                    run = tmp -> children[j];
                    if (query(word + i + 1, run))
                        return true;
                }
            }
            else break;
        }
        return run && run -> isKey; 
    }
};