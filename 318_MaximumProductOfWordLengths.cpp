//8.67%
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size() <= 1)
			return 0;
		int res(0);
		for(int i = 1; i < words.size(); ++i){
			int currSize(0);
			for(int j = 0; j < i; ++j){
				//if(words[j].size() <= currSize)
				//	continue;
				if(diffWords(words[i], words[j])){
					res = max(res, int(words[i].size() * words[j].size()));
					currSize = words[j].size();
				}
			}
		}
		return res;
    }
private:
	bool diffWords(const string& word1, const string& word2){
		//if(word1.size() < word2.size())
		//	return diffWords(word2, word1);
		vector<bool> flagArray(26);
		for(int i = 0; i < word2.size(); ++i){
			flagArray[word2[i] - 'a'] = true;
		}
		for(int i = 0; i < word1.size(); ++i){
			if(flagArray[word1[i] - 'a'])
				return false;
		}
		return true;
	}
};

//63.06%
//By using bits-manipulation
int maxProduct(vector<string>& words) {
    vector<int> mask(words.size());
    int result = 0;
    for (int i=0; i<words.size(); ++i) {
        for (char c : words[i])
            mask[i] |= 1 << (c - 'a');
        for (int j=0; j<i; ++j)
            if (!(mask[i] & mask[j]))
                result = max(result, int(words[i].size() * words[j].size()));
    }
    return result;
}