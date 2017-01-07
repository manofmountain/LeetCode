class Solution {
public:
    string countAndSay(int n) 
	{
		string resStr;
		if(n < 1)
			return resStr;
		
		resStr = "1";
		
		
		for(int k = 2; k <= n; k++)
		{
			char curChar = resStr[0];
			resStr.push_back('#'); //Boundary conditions, then we won't need to consider to have left 'characters' included
			int times = 1;
			string tempStr;
			for(int i = 1; i < resStr.size(); i++)
			{
				char temChar = resStr[i];
				if(temChar == curChar)
					times++;
				else
				{
					tempStr += to_string(times);
					tempStr.push_back(curChar);
					curChar = temChar;
					times = 1;
				}
			
			}
			resStr = tempStr;
		}
		return resStr;
    }
};