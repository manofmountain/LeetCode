//Timeout Limit
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		int pLen(p.size());
		int sSize(s.size());
		if(sSize < pLen)
			return res;
		
		multiset<char> sp(p.begin(), p.end());
		for(int i = 0; i <= sSize - pLen; i++){
			multiset<char> ss(s.begin() + i, s.begin() + i + pLen);
			if(ss == sp)
				res.push_back(i);
		}
		return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		int pLen(p.size());
		int sSize(s.size());
		if(sSize < pLen)
			return res;
		
		unordered_map<char, int> mapP;
		for(auto c : p)
			mapP[c]++;
		
		for(int i = 0; i <= sSize - pLen;){
			unordered_map<char, int> temp(mapP);
			int j(0);
			for(; j < pLen; j++){
				if(--temp[s[i + j]] < 0)
					break;
			}
			if(j == pLen)
				res.push_back(i++);
			else
				i += j;
		}
		return res;
    }
};

//Sliding window solution
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26,0), sv(26,0), res;
        if(s.size() < p.size())
           return res;
        // fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv == sv)
           res.push_back(0);

        //here window is moving from left to right across the string. 
        //window size is p.size(), so s.size()-p.size() moves are made 
        for(int i = p.size(); i < s.size(); ++i) 
        {
             // window extends one step to the right. counter for s[i] is incremented 
            ++sv[s[i]-'a'];
            
            // since we added one element to the right, 
            // one element to the left should be forgotten. 
            //counter for s[i-p.size()] is decremented
            --sv[s[i-p.size()]-'a']; 

            // if after move to the right the anagram can be composed, 
            // add new position of window's left point to the result 
            if(pv == sv)  
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};

//256 character version:
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(256,0), sv(256,0), res;
        if(s.size() < p.size())
           return res;
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]];
            ++sv[s[i]];
        }
        if(pv == sv)
           res.push_back(0);
        for(int i = p.size(); i < s.size(); ++i)
        {
            ++sv[s[i]];
            --sv[s[i-p.size()]];
            if(pv == sv)
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};


