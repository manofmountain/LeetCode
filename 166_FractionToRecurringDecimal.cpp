class Solution {
//6.75%
public:
    string fractionToDecimal(int numerator, int denominator) {
		//if(numerator == 0)
		//	return "0";
		long newNumerator(numerator), newDenominator(denominator);
        if(newNumerator % newDenominator == 0)
			return to_string(newNumerator / newDenominator);
		string res(to_string(newNumerator / newDenominator) + ".");
		if(res == "0."){
			if(newNumerator < 0 && newDenominator > 0 || newNumerator > 0 && newDenominator < 0)
				res = "-" + res;
		}
		newNumerator = abs(newNumerator % newDenominator);
		newDenominator = abs(newDenominator);
		unordered_map<int, int> traced;
		int cnt(0);
		while(newNumerator){
			traced[newNumerator] = cnt++;
			int newPart(newNumerator * 10 / newDenominator);
			newNumerator = newNumerator * 10 % newDenominator;
			if(newNumerator == 0)
				return res + to_string(newPart);
			else if(traced.find(newNumerator) != traced.end()){
				cnt -= traced[newNumerator];
				res += to_string(newPart);
				return res.substr(0, res.size() - cnt) + "(" + res.substr(res.size() - cnt, cnt) + ")";
			}else
				res += to_string(newPart);
		}
		return res;			
    }
};

//A good solution from LeetCode
// upgraded parameter types
string fractionToDecimal(int64_t n, int64_t d) {
    // zero numerator
    if (n == 0) return "0";

    string res;
    // determine the sign
    if (n < 0 ^ d < 0) res += '-';

    // remove sign of operands
    n = abs(n), d = abs(d);

    // append integral part
    res += to_string(n / d);

    // in case no fractional part
    if (n % d == 0) return res;

    res += '.';

    unordered_map<int, int> map;

    // simulate the division process
    for (int64_t r = n % d; r; r %= d) {

        // meet a known remainder
        // so we reach the end of the repeating part
        if (map.count(r) > 0) {
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }

        // the remainder is first seen
        // remember the current position for it
        map[r] = res.size();

        r *= 10;

        // append the quotient digit
        res += to_string(r / d);
    }

    return res;
}

//A more clean code
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        long integral = numer / denom;
        res += to_string(integral);
        long rmd = numer % denom;
        if (!rmd) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, long> mp; 
        while (rmd) {
            long quotient = rmd / denom;
            if (mp.find(rmd) != mp.end()) { 
                res.insert(mp[rmd], 1, '(');
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            res += to_string(quotient);
            rmd = (rmd % denom) * 10;
        }
        return res;
    }
};