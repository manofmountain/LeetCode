//62.2%
//In this way, it's too complex
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step(0);
		unordered_set<string> traced;
		//Check if 'endWord' within wordList
		for(;step < wordList.size(); ++step)
			if(wordList[step] == endWord)
				break;
		if(step == wordList.size())
			return 0;
		
		step = 0;
		vector<string> candidates(1, endWord);
		traced.insert(endWord);
		while(!candidates.empty()){
			++step;
			for(auto& candidate : candidates){
				if(diffWord(candidate, beginWord) == 1)
					return step + 1;
			}
			vector<string> newCandidates;
			for(auto& word : wordList){
				if(traced.find(word) == traced.end()){
					for(auto& candidate : candidates){
						if(diffWord(candidate, word) == 1){
							newCandidates.push_back(word);
							traced.insert(word);
							break;
						}
					}
				}
			}
			candidates = newCandidates;
		}
		return 0;
    }
private:
	//cnt: different letters' number
	int diffWord(const string& firstWord, const string& secondWord){
		int cnt(0);
		for(int i = 0; i < firstWord.size(); ++i){
			if(firstWord[i] != secondWord[i]){
				if(!cnt)
					++cnt;
				else
					return 2;
			}
		}
		return cnt;
	}
};

//It's a typical use case with 'BFS'
//If we're using 'unordered_set' data structure on wordDict
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(endWord);
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            for (int i = 0; i < num; i++) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                addNextWords(word, wordDict, toVisit);
            }
            dist++;
        }
		return 0;
    }
private:
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        for (int p = 0; p < (int)word.length(); p++) {
            char letter = word[p];
            for (int k = 0; k < 26; k++) { 
                word[p] = 'a' + k;
                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[p] = letter;
        } 
    } 
};


//A two ends starting search problem to speed up the whole programme
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail; 
                ptail = &head;
            }
            unordered_set<string> temp; 
            for (auto itr = phead -> begin(); itr != phead -> end(); itr++) {
                string word = *itr;
                wordDict.erase(word);
                for (int p = 0; p < (int)word.length(); p++) {
                    char letter = word[p];
                    for (int k = 0; k < 26; k++) {
                        word[p] = 'a' + k;
                        if (ptail -> find(word) != ptail -> end())
                            return dist;
                        if (wordDict.find(word) != wordDict.end()) {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            dist++;
            swap(*phead, temp);
        }
        return 0; 
    }
};