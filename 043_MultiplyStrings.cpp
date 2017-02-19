//My naive plain way, but it did work in my machine
class Solution {
public:
    string multiply(string num1, string num2) {
        int size1(num1.size()), size2(num2.size());
		if(size1 > size2)
			multiply(num2, num1);
		
		string res("0");
		int weight(0);
		for(int i = size1 - 1; i >= 0; i--){
			if(num1[i] != '0')
				multiplyHelper(num1[i], weight, num2, res);
			weight += 1;
		}
		return res;
    }
private:
	void multiplyHelper(char c, int weight, const string& num, string& res){
		string medium;
		int digit(c - '0');
		int remain(0);
		int temp(0);
		for(int i = num.size() - 1; i >= 0; i--){
			temp = (num[i] - '0') * digit + remain;
			medium = char(temp % 10 + '0') + medium;
			remain = temp / 10;
		}
		if(remain)
			medium = char(remain + '0') + medium;
		if(weight){
			string zeroNum(weight, '0');
			medium = num + zeroNum;
		}
		addTwoStrings(medium, res);
	}
	
	void addTwoStrings(const string& num, string& res){
		if(res.empty()) res = num;
		int i(res.size() - 1), j(num.size() - 1);
		int remain(0);
		while(j >= 0 || remain){
			int medium(remain);
			medium += (i >= 0 ? res[i] - '0' : 0);
			medium += (j >= 0 ? num[j] - '0' : 0);
			char temp(medium % 10 + '0');
			if(i >= 0)
				res[i--] = temp;
			else
				res = temp + res;
			j--;
			remain = medium / 10;
		}
	}
};

//My old way
class Solution {
public:
    string multiply(string num1, string num2) 
	{
		string res;
        int len1 = num1.size();
		int len2 = num2.size();
		if(len1 <= 0 || len2 <= 0)
			return res;
		
		vector<int> resArray(len1 + len2, 0);
		int len3 = len1 + len2 - 2;
		for(int i = 0; i < len1; i++)
		{
			int temp1 = num1[i] - '0';
			for(int j = 0; j < len2; j++)
			{	
				int temp2 = num2[j] - '0';
				resArray[len3 - i - j] += (temp1 * temp2);
			}
		}
		
		int carryFlag = 0;
		for(int i = 0; i <= (len3 + 1); i++)
		{
			int temp = resArray[i];
			temp += carryFlag;
			resArray[i] = temp % 10;
			carryFlag = temp / 10;
		}
		
		//Filter out non-business zeroes
		int i = len3 + 1;
		while(i >= 0 && resArray[i] == 0)
			i--;
		if(i < 0)
		{
			return "0";
		}
		
		while(i >= 0)
		{
			char temp = resArray[i] + '0';
			res.push_back(temp);
			i--;
		}
		
		return res;
    }
};

//A better way in C++
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}