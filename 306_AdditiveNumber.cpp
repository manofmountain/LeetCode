//58.78%
class Solution {
public:
    bool isAdditiveNumber(string num) {
       if(num.size() < 3)
			return false;
		int size(num.size());
		int first(0), second(0);
		//if(num[0] == '0')
		//	return false;
		for(int i = 0; i <= size / 2; ++i){
			second = 0;
			first = first * 10 + num[i] - '0';
			if(num[i + 1] == '0'){
				if(isValid(num, i + 2, size, first, second))
					return true;
				if(0 == first)
					break;
				continue;
			}

			for(int j = i + 1; j < size; ++j){
				second = second * 10 + num[j] - '0';
				if(isValid(num, j + 1, size, first, second))
					return true;
			}
			if(0 == first)
				break;
		}
		return false;
    }
private:
	bool isValid(const string& num, int left, int right, long first, long second){
		string three(to_string(first + second));
		if(num.substr(left, three.size()) == three){
			if(left + three.size() == right)
				return true;
			else
				return isValid(num, left + three.size(), right, second, first + second);
		}
		return false;
	}
};

//Another thinking way which is different with mine
class Solution {
public:
        bool isAdditiveNumber(string num) {
            for(int i=1; i<=num.size()/2; i++){
                for(int j=1; j<=(num.size()-i)/2; j++){
                    if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
                }
            }
            return false;
        }
        bool check(string num1, string num2, string num){
            if(num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;
            string sum=add(num1, num2);
            if(num==sum) return true;
            if(num.size()<=sum.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
            else return check(num2, sum, num.substr(sum.size()));
        } 
        string add(string n, string m){
            string res;
            int i=n.size()-1, j=m.size()-1, carry=0;
            while(i>=0 || j>=0){
                int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
                res.push_back(sum%10+'0');
                carry=sum/10;
            }
            if(carry) res.push_back(carry+'0');
            reverse(res.begin(), res.end());
            return res;
        }
    };