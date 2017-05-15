//5.79%
class Solution {
public:
    int lengthLongestPath(string input) {
        if(input.empty())
			return 0;
		int maxLen(0), currIndex(0), currLen(0);
		bool isFile(false);
		vector<int> s;
		int i = 0;
		while(i < input.size()){
			if(input[i] == '\t'){
				++currIndex;
			}else if(input[i] == '.'){
				isFile = true;
				++currLen;
			}else if(input[i] == '\n'){
				if(!isFile){
					if(currIndex == s.size())
						if(s.empty())
							s.push_back(currLen);
						else
							s.push_back(currLen + s.back());
					else
						s[currIndex] = s[currIndex - 1] + currLen;
				}else{
					maxLen = max(maxLen, currLen + s[currIndex - 1] + currIndex);
					isFile = false;
				}
				currLen = 0;
				currIndex = 0;
			}else
				++currLen;
			++i;
		}
		if(isFile){
			if(s.empty())
				maxLen = max(maxLen, currLen);
			else
				maxLen = max(maxLen, currLen + s[currIndex - 1] + currIndex);
		}
		return maxLen;
    }
};

//5.79%
class Solution {
public:
    int lengthLongestPath(string input) {
        if(input.empty())
			return 0;
		size_t index(input.find_first_of('\n'));
		if(index == string::npos){
			if(input.find_first_of('.') != string::npos)
				return input.size();
			else
				return 0;
		}
		int maxLen(0), currIndex(0), currLen(0);
		bool isFile(false);
		vector<int> s(1, index);
		int i = index + 1;
		while(i < input.size()){
			if(input[i] == '\t'){
				++currIndex;
			}else if(input[i] == '.'){
				isFile = true;
				++currLen;
			}else if(input[i] == '\n'){
				if(!isFile){
					if(currIndex == s.size())
						s.push_back(currLen + s.back());
					else
						s[currIndex] = s[currIndex - 1] + currLen;
				}else{
					maxLen = max(maxLen, currLen + s[currIndex - 1] + currIndex);
					isFile = false;
				}
				currLen = 0;
				currIndex = 0;
			}else
				++currLen;
			++i;
		}
		if(isFile)
			maxLen = max(maxLen, currLen + s[currIndex - 1] + currIndex);
		return maxLen;
    }
};


public:
    int lengthLongestPath(string input) {
        int maxi=0,count=0,ln=1;
        bool isFile=false;
        vector<int> level(200);
        level[0]=0;
        for(int i=0,fin=input.size();i<fin;++i){
            //find which level
            while(input[i]=='\t'){
                ++ln;++i;
            }
            //read file name
            while(input[i]!='\n'&&i<fin){
                if(input[i]=='.')isFile=true;
                ++count;++i;
            }
            //calculate
            if(isFile){
                maxi=max(maxi,level[ln-1]+count);
            }
            else{
                level[ln]=level[ln-1]+count+1;// 1 means '/'
            }
            //reset
            count=0;ln=1;isFile=false;
        }
        return maxi;
    }
};