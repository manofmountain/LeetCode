class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Boundary conditions check
		int size = strs.size();
		if(0 == size)
			return "";
		if(1 == size)
			return strs[0];
		
		bool flag = true;
		int sizeFirst = strs[0].size();
		int pos = 0;
		for(pos = 0; pos < sizeFirst; pos++)
		{
			char charFirst = strs[0][pos];
			for(int indexStrs = 1; indexStrs < size; indexStrs++)
				if(pos >= strs[indexStrs].size() || strs[indexStrs][pos] != charFirst)
				{
					flag = false;
					break;
				}
			if(!flag)
				break;
		}
		
		return strs[0].substr(0, pos);
    }
};

//17.11%
class Solution001 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Boundary conditions check
		int size = strs.size();
		if(0 == size)
			return "";
		if(1 == size)
			return strs[0];
		
		bool flag = true;
		int sizeFirst = strs[0].size();
		int pos = 0;
		for(pos = 0; pos < sizeFirst; pos++)
		{
			char charFirst = strs[0][pos];
			for(int indexStrs = 1; indexStrs < size; indexStrs++)
				if(pos >= strs[indexStrs].size() || strs[indexStrs][pos] != charFirst)
				{
					flag = false;
					break;
				}
			if(!flag)
				break;
		}
		
		return strs[0].substr(0, pos);
    }
};