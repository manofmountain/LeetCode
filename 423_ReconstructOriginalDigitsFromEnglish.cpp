//A more concise C++ way
class Solution {
public:
    string originalDigits(string s) {
        vector<int> a(10, 0);
        vector<int> alpha(128, 0);
        for (char c : s)
            alpha[c]++;
        a[0] = alpha['z'];
        a[2] = alpha['w'];
        a[4] = alpha['u'];
        a[6] = alpha['x'];
        a[8] = alpha['g'];
        a[3] = alpha['h'] - a[8];
        a[5] = alpha['f'] - a[4];
        a[7] = alpha['v'] - a[5];
        a[1] = alpha['o'] - a[0] - a[2] - a[4];
        a[9] = alpha['i'] - a[5] - a[6] - a[8];
        string ans;
        for (int i = 0; i < 10; i++) {
            if (a[i] > 0)
                ans += string(a[i], '0' + i);
        }
        return ans;
    }
};


class Solution {
public:
    string originalDigits(string s) {
        vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        vector<int> counts(26, 0);
        string result;
        for(auto ch : s){ counts[ch-'a']++;}
        for(int i = 0; i < 10; i++){
            int count = counts[distinct_char[i]-'a'];
            for(int j = 0; j < words[i].size(); j++)
                counts[words[i][j]-'a'] -= count;
            while(count--)
                result += to_string(nums[i]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

//A better and more concise Java solution
public String originalDigits(String s) {
    int[] count = new int[10];
    for (int i = 0; i < s.length(); i++){
        char c = s.charAt(i);
        if (c == 'z') count[0]++;
        if (c == 'w') count[2]++;
        if (c == 'x') count[6]++;
        if (c == 's') count[7]++; //7-6
        if (c == 'g') count[8]++;
        if (c == 'u') count[4]++; 
        if (c == 'f') count[5]++; //5-4
        if (c == 'h') count[3]++; //3-8
        if (c == 'i') count[9]++; //9-8-5-6
        if (c == 'o') count[1]++; //1-0-2-4
    }
    count[7] -= count[6];
    count[5] -= count[4];
    count[3] -= count[8];
    count[9] = count[9] - count[8] - count[5] - count[6];
    count[1] = count[1] - count[0] - count[2] - count[4];
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i <= 9; i++){
        for (int j = 0; j < count[i]; j++){
            sb.append(i);
        }
    }
    return sb.toString();
}


//76.08%
class Solution {
public:
    string originalDigits(string s) {
        if(s.empty())
			return s;
		const int ALPHA_NUM(26);
		const int DIGIT_NUM(10);
		vector<int> lettersTable(ALPHA_NUM);
		//vector<char> digitsUniqueLetters {'z', 'o', 'w', 'h', 'u', 'f', 'x', 's', 'g', 'n'};
		//vector<vector<char> > digitsNonUniqueLetters { {'e', 'r', 'o'}, {'n', 'e'}, {'t', 'o'}, {'t', 'r', 'e
		vector<int> digitsTable(DIGIT_NUM);
		
		for(char c : s)
			++lettersTable[c - 'a'];
		
		//for(int i = 0; i <= 8; i += 2){
			
		
		//Check '0' <-> 'z', '2' <-> 'w', '4' <-> 'u', '6' <-> 'x', '8' <-> 'g' at first
		//Check '0' first
		if(lettersTable['z' - 'a'] > 0){
			digitsTable[0] = lettersTable['z' - 'a'];
			lettersTable['e' - 'a'] -= lettersTable['z' - 'a'];
			lettersTable['r' - 'a'] -= lettersTable['z' - 'a'];
			lettersTable['o' - 'a'] -= lettersTable['z' - 'a'];
		}
		
		//Check '2'
		if(lettersTable['w' - 'a'] > 0){
			digitsTable[2] = lettersTable['w' - 'a'];
			lettersTable['t' - 'a'] -= lettersTable['w' - 'a'];
			lettersTable['o' - 'a'] -= lettersTable['w' - 'a'];
		}
		
		//Check '4'
		if(lettersTable['u' - 'a'] > 0){
			digitsTable[4] = lettersTable['u' - 'a'];
			lettersTable['f' - 'a'] -= lettersTable['u' - 'a'];
			lettersTable['o' - 'a'] -= lettersTable['u' - 'a'];
			lettersTable['r' - 'a'] -= lettersTable['u' - 'a'];
		}
		
		//Check '6'
		if(lettersTable['x' - 'a'] > 0){
			digitsTable[6] = lettersTable['x' - 'a'];
			lettersTable['s' - 'a'] -= lettersTable['x' - 'a'];
			lettersTable['i' - 'a'] -= lettersTable['x' - 'a'];
		}
		
		//Check '8'
		if(lettersTable['g' - 'a'] > 0){
			digitsTable[8] = lettersTable['g' - 'a'];
			lettersTable['e' - 'a'] -= lettersTable['g' - 'a'];
			lettersTable['i' - 'a'] -= lettersTable['g' - 'a'];
			lettersTable['h' - 'a'] -= lettersTable['g' - 'a'];
			lettersTable['t' - 'a'] -= lettersTable['g' - 'a'];
		}
		
		//Check '1'
		if(lettersTable['o' - 'a'] > 0){
			digitsTable[1] = lettersTable['o' - 'a'];
			lettersTable['n' - 'a'] -= lettersTable['o' - 'a'];
			lettersTable['e' - 'a'] -= lettersTable['o' - 'a'];
		}
		
		//Check '3'
		if(lettersTable['h' - 'a'] > 0){
			digitsTable[3] = lettersTable['h' - 'a'];
			lettersTable['t' - 'a'] -= lettersTable['h' - 'a'];
			lettersTable['r' - 'a'] -= lettersTable['h' - 'a'];
			lettersTable['e' - 'a'] -= 2 * lettersTable['h' - 'a'];
		}
		
		//Check '5'
		if(lettersTable['f' - 'a'] > 0){
			digitsTable[5] = lettersTable['f' - 'a'];
			lettersTable['i' - 'a'] -= lettersTable['f' - 'a'];
			lettersTable['v' - 'a'] -= lettersTable['f' - 'a'];
			lettersTable['e' - 'a'] -= 2 * lettersTable['f' - 'a'];
		}
		
		//Check '7'
		if(lettersTable['s' - 'a'] > 0){
			digitsTable[7] = lettersTable['s' - 'a'];
			lettersTable['s' - 'a'] -= lettersTable['s' - 'a'];
			lettersTable['v' - 'a'] -= lettersTable['s' - 'a'];
			lettersTable['e' - 'a'] -= 2 * lettersTable['s' - 'a'];
			lettersTable['n' - 'a'] -= lettersTable['s' - 'a'];
		}
		
		//Check '9'
		if(lettersTable['i' - 'a'] > 0)
			digitsTable[9] = lettersTable['i' - 'a'];
		
		
		//Combination
		string res;
		for(int i = 0; i < DIGIT_NUM; ++i){
			string temp(to_string(i));
			while(digitsTable[i]--)
				res += temp;
		}
		return res;
    }
};