//A clear solution
class Solution {
public:
    string getPermutation(int n, int k) 
	{
		string str = string("123456789").substr(0, n);
		string res(n, ' ');
		for(int i = 0; i < n; i++)
			res[i] = helper(str, k);
		
		return res;
    }
	
	char helper(string &s, int &k)
	{
		int tmp = factorial(s.size() - 1), i = (k - 1) / tmp;
		char res = s[i];
		s.erase(i, 1);
		k -= i * tmp;
		
		return res;
	}
	
	int factorial(int n)
	{
		int res = 1;
		for(int i = 2; i <= n; i++)
			res *= i;
		return res;
	}
};

//A better iterative way
string getPermutation(int n, int k) {
    int i,j,f=1;
    // left part of s is partially formed permutation, right part is the leftover chars.
    string s(n,'0');
    for(i=1;i<=n;i++){
        f*=i;
        s[i-1]+=i; // make s become 1234...n
    }
    for(i=0,k--;i<n;i++){
        f/=n-i;
        j=i+k/f; // calculate index of char to put at s[i]
        char c=s[j];
        // remove c by shifting to cover up (adjust the right part).
        for(;j>i;j--)
            s[j]=s[j-1];
        k%=f;
        s[i]=c;
    }
    return s;
}

//Another more C++ way
string getPermutation(int n, int k) {
    int pTable[10] = {1};
    for(int i = 1; i <= 9; i++){
        pTable[i] = i * pTable[i - 1];
    }
    string result;
    vector<char> numSet;
    numSet.push_back('1');
    numSet.push_back('2');
    numSet.push_back('3');
    numSet.push_back('4');
    numSet.push_back('5');
    numSet.push_back('6');
    numSet.push_back('7');
    numSet.push_back('8');
    numSet.push_back('9');
    while(n > 0){
        int temp = (k - 1) / pTable[n - 1];
        result += numSet[temp];
        numSet.erase(numSet.begin() + temp);
        k = k - temp * pTable[n - 1];
        n--;
    }
    return result;
}



//I didn't finish mine as it's too complex
class Solution {
public:
    string getPermutation(int n, int k) {
		string res;
        if(n <= 0 || k <= 0)
			return res;
		//m! not smaller than k 'm! >= k'
		//flag: means if 'm! == k'
		bool flag(false);
		vector<int> nums(n);
		for(int i = 1; i <= n; i++)
			nums[i - 1] = i;
		int m_pre(0);
		int start(1);
		int end(n);
		while(k > 0){
			int m = closeLargerM(k, flag, m_pre);
			if(m > end)
				return res;
			for(int i = 1; i <= end - m; i++){
				res += to_string(nums[start + i - 1]);
			}
			if(flag){
				for(int i = end; i > end - m; i--){
					res += to_string(nums[start + i - 1]);
				}
				return res;
			}
			//m_pre 
			res += to_string(nums[start + end - m - 1 + m_pre]);
			for(int i = end - m + 1; i < end - m  - 1 + m_pre; i++)
				nums[start + i] = nums[start + i - 1];
			k -= (factorial[m - 1] * (m_pre));
			start = n - m + 2;
			end = m - 1;
		}
		return res;
    }
};