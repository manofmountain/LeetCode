
//38.13
class Solution {
public:
    int myAtoi(string str) {
		long rst(0);
		int index(str.find_first_not_of(' '));
		int flag(1);
		if(str[index] == '+' || str[index] == '-')
			flag = (str[index++] == '-')?(-1):1;
		
		//int size(str.size());
		while(str[index] >= '0' && str[index] <= '9')
		{
			rst = rst * 10 + (str[index++] - '0');	
			if(rst * flag >= INT_MAX)
				return INT_MAX;
			if(rst * flag <= INT_MIN)
				return INT_MIN;
		}
		
		return rst * flag;
    }
};
//10.09%
class Solution001 {
public:
    int myAtoi(string str) {
		long rst(0);
		int index = str.find_first_not_of(' ');
		int flag(1);
		if(str[index] == '+' || str[index] == '-')
			flag = (str[index++] == '-')?(-1):1;
		
		int size = str.size();
		while(index < size)
		{
			if(str[index] >= '0' && str[index] <= '9')
			{
				rst = rst * 10 + (str[index++] - '0');
				
				if(rst * flag >= INT_MAX)
					return INT_MAX;
				if(rst * flag <= INT_MIN)
					return INT_MIN;
			}
			else
				break;
		}
		
		return rst * flag;
    }
};