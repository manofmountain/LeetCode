//9.51%
class Solution {
public:
    string addStrings(string num1, string num2) {
		int size1(num1.size());
		int size2(num2.size());
		int maxSize(size1);
		if(size1 >= size2){
			for(int i = 0; i < size1 - size2; i++)
				num2 = "0" + num2;
		}else{
			maxSize = size1;
			for(int i = 0; i < size2 - size1; i++)
				num1 = "0" + num1;
		}
		int remain(0);
		string res;
		for(string::reverse_iterator r1 = num1.rbegin(), r2 = num2.rbegin(); r1 != num1.rend(); r1++, r2++){
			int num = (*r1 - '0') + (*r2 - '0') + remain;
			remain = num / 10;
			res = char('0' + num % 10) + res;
		}
		if(remain)
			res = '1' + res;
		return res;	
    }
};

class Solution {
public:
string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry; 
        carry = sum / 10;
        sum = sum % 10;
        res =  res + to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}
};

//A better solution which use O(1) space
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) return addStrings(num2, num1);
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
        for (; i >= 0 && (carry || j >= 0); i--, j--, carry /= 10) 
            num1[i] = (carry += num1[i] - '0' + (j >= 0 ? num2[j] - '0' : 0)) % 10 + '0';
        return (carry ? "1" : "") + num1;
    }
};