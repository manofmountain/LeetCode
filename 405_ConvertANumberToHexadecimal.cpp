//4.53%
class Solution {
public:
    string toHex(int num) { 
		if(!num)
			return to_string(num);
		string s[] = {"a", "b", "c", "d", "e", "f"};
		//vector<string> l(s, s + 6);
		int mask(0xf);
		int step(4);
		string res;
		int sizeInt(8); //8 * half byte
		int i(0);
		while(num && i < sizeInt){
			int temp = num & mask;
			if(temp < 10)
				res += to_string(temp);
			else
				res += s[temp - 10];
			num >>= step;
			i++;
		}
		
		//Reverse the string 'res'
		reverse(res.begin(), res.end());
		return res;
    }
};

const string HEX = "0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) {
            result = HEX[(num & 0xf)] + result;
            num >>= 4;
        }
        return result;
    }
};

class Solution {
public:
    string toHex(int num) {
        int count = 0;
        if(!num) return "0";
        string result;
        while (num && count < 8)
        {
            int temp = num & 15;
            if (temp<10)    result.push_back('0'+ temp);
            else result.push_back('a'+temp-10);
            num = num >> 4;
            count++;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};