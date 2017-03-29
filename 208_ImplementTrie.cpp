//10.86%
class Trie {
public:
    /** Initialize your data structure here. */
    Trie():trees(AlphaNumber) {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.empty())
			return;
		if(!(trees[word[0] - 'a'].first))
			trees[word[0] - 'a'].first = new Trie;
		if(word.size() == 1){
			trees[word[0] - 'a'].second = true;
			return;
		}
		trees[word[0] - 'a'].first -> insert(word.substr(1));
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		if(word.empty())
			return true;
        if(!trees[word[0] - 'a'].first)
			return false;
		if(word.size() == 1)
			return trees[word[0] - 'a'].second;
		return trees[word[0] - 'a'].first -> search(word.substr(1));
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.empty())
			return true;
		if(!trees[prefix[0] - 'a'].first)
			return false;
		return trees[prefix[0] - 'a'].first -> startsWith(prefix.substr(1));
    }
private:
	const static int AlphaNumber = 26;
	vector<pair<Trie *, bool> > trees;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
 
 

//A C++ solution from LeetCode 
 class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }

private:
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};