//31.93%
class Solution {
public:
    string convert(string s, int numRows) {
        //Check the boundary conditions
		int size = s.size();
		if(size <= numRows || 1 >= numRows)
			return s;
		
		//Put each string into related row string vector
		vector<string> strRows(numRows, "");
		string rst("");
		int rowIndex = 0;
		bool flag = true; //true while downwards and false while upwards
		for(int index = 0; index < size; index++)
		{
			if(flag)
			{
				if(rowIndex != numRows - 1)
					strRows[rowIndex++] += s[index];
				else
				{
					strRows[rowIndex--] += s[index];
					flag = false;
				}
			}
			else
			{
				if(rowIndex)
					strRows[rowIndex--] += s[index];
				else
				{
					strRows[rowIndex++] += s[index];
					flag = true;
				}
			}
		}
		
		//Combine all row sub-strings into a whole 'rst' string
		for(int rowIndex = 0; rowIndex < numRows; rowIndex++)
			rst += strRows[rowIndex];
		
		return rst;
    }
};


//%15.92
class Solution001 {
public:
    string convert(string s, int numRows) {
        //Check the boundary conditions
		int size = s.size();
		if(size <= numRows || 1 >= numRows)
			return s;
		
		//Put each string into related row string vector
		vector<string> strRows(numRows, "");
		string rst("");
		int rowIndex = 0;
		bool flag = true; //true while downwards and false while upwards
		for(int index = 0; index < size; index++)
		{
			if(rowIndex < numRows && flag)
				strRows[rowIndex++] += s[index];
			else if(flag)
			{
				rowIndex -= 2;
				strRows[rowIndex] += s[index];
				if(rowIndex)
				{
					rowIndex--;
					if(rowIndex)
						flag = false;
				}
				else
					rowIndex++;
			}
			else
			{
				strRows[rowIndex--] += s[index];
				if(!rowIndex)
					flag = true;
			}
		}
		
		//Combine all row sub-strings into a whole 'rst' string
		for(int rowIndex = 0; rowIndex < numRows; rowIndex++)
			rst += strRows[rowIndex];
		
		return rst;
    }
};