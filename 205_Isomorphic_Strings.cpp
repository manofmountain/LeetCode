//29.36%
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //const int charNum(256);
		unordered_map<char, char> mapS, mapT;
		for(string::const_iterator iteS = s.begin(), iteT = t.begin(); iteS != s.end(); iteS++, iteT++){
			unordered_map<char, char>::iterator posS = mapS.find(*iteS);
			unordered_map<char, char>::iterator posT = mapT.find(*iteT);
			if( posS == mapS.end() && posT == mapT.end()){
				mapS[*iteS] = *iteT;
				mapT[*iteT] = *iteS;
			}else if(posS != mapS.end() && mapS[*iteS] != *iteT || posT != mapT.end() && mapT[*iteT] != *iteS)
				return false;
		}
		return true;
    }
};

//A simpler and more efficient solution from LeetCode
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};