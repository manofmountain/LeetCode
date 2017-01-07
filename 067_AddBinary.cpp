//A beautiful code from LeetCode
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";
        //Here 'c' means carry flag
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
};

//Another solution from LeetCode
string addBinary(string a, string b) 
{
    string result = "";
    int apos = a.size() - 1;
    int bpos = b.size() - 1;
    int adigit, bdigit, carry = 0;
    
    while (apos >= 0 || bpos >= 0 || carry == 1)
    {
        adigit = bdigit = 0;
        
        if (apos >= 0) adigit = a[apos--] == '1';
        if (bpos >= 0) bdigit = b[bpos--] == '1';
        
        // Another way: the digit is 1 if adigit + bdigit + carry == 1 or == 3, but I noticed that
        // XOR is more concise:
        result = static_cast<char>(adigit ^ bdigit ^ carry + '0') + result; 
        carry = adigit + bdigit + carry >= 2;
    }
    
    return result;
}

//I like this one
class Solution {
public:
        string addBinary(string a, string b) {
                string ret = "";
                int carry = 0;
                for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
                        int m = (i >= 0 && a[i] == '1');
                        int n = (j >= 0 && b[j] == '1');
                        ret = to_string((m + n + carry) & 0x1) + ret;
                        carry = (m + n + carry) >> 1;
                }
                return carry ? '1' + ret : ret;
        }
};