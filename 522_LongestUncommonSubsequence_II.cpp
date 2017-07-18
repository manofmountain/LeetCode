//It's correct on my desktop, but didn't pass on the website
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
		vector<set<string>> strSets(11);
		vector<bool> sameExists(11);
		for(int i = 0; i < strs.size(); ++i){
			int size(strs[i].size());
			if(strSets[size].find(strs[i]) != strSets[size].end())
				sameExists[size] = true;
			else
				strSets[size].insert(strs[i]);
		}
		
		int len = 10;
		while(len >= 0){
			if(sameExists[len] || strSets[len].empty()){
				--len;
				continue;
			}
			int ll(len + 1);
			while(ll <= 10){
				if(strSets[ll].empty()){
					++ll;
					continue;
				}
				if(helper(strSets, len, ll))
					break;
				++ll;
			}
			if(ll == 11)
				return len;
			--len;
		}
		return -1;
    }
private:
	bool helper(const vector<set<string>>& strSets, int len, int ll){
		for(const string& str1 : strSets[len]){
			bool isSequence(false);
			for(const string& str2 : strSets[ll]){
				if(isSubSequence(str1, str2)){
					isSequence = true;
					break;
				}
			}
			if(!isSequence)
				return false;
		}
		return true;
	}
	
	bool isSubSequence(const string& str1, const string& str2){
		size_t index1(0), index2(0);
		while(index1 != str1.size() && index2 != str2.size()){
			if(str1[index1] == str1[index2]){
				++index1;
				++index2;
			}else
				++index2;
		}
		return index1 == str1.size();
	}		
};

//Below is an accepted solution
bool cmp(pair<string,int> &a, pair<string,int> &b)
{
    return a.first.size() > b.first.size();
}

bool isS1subsOfS2(string &s1, string &s2){
    int j = 0, i = 0;
    for(; i < s1.size(); ++i){
        while(j < s2.size() && s1[i] != s2[j]) ++j;
        if(j == s2.size())
           return false;
        ++j;
    }
    return true;
}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,int> m;
        for(int i = 0; i < strs.size(); ++i)
          ++m[strs[i]];
        vector<pair<string,int>> v;
        for(auto it = m.begin(); it != m.end(); ++it)
           v.push_back(*it);
        sort(v.begin(),v.end(),cmp);
        for(int i = 0; i < v.size(); ++i)
        {
           if(v[i].second == 1){
               int j = 0;
               for(; j < i; ++j)
                 if(isS1subsOfS2(v[i].first,v[j].first))
                     break;
               if(j == i) return v[i].first.size();
           }
        }
        return -1;
    }
};
//A reall non-optimal Java solution
public int findLUSlength(String[] strs) {
    Map<String, Integer> subseqFreq = new HashMap<>();
    for (String s : strs) 
        for (String subSeq : getSubseqs(s))
            subseqFreq.put(subSeq, subseqFreq.getOrDefault(subSeq, 0) + 1);
    int longest = -1;
    for (Map.Entry<String, Integer> entry : subseqFreq.entrySet()) 
        if (entry.getValue() == 1) longest = Math.max(longest, entry.getKey().length());
    return longest;
}

public static Set<String> getSubseqs(String s) {
    Set<String> res = new HashSet<>();
    if (s.length() == 0) {
         res.add("");
         return res;
    }
    Set<String> subRes = getSubseqs(s.substring(1));
    res.addAll(subRes);
    for (String seq : subRes) res.add(s.charAt(0) + seq);
    return res;
}