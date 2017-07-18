//5.23%
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        if(a.empty() || b.empty())
			return "0+0i";
		size_t plusPosA;// = a.find_first_of('+');
		size_t plusPosB; // = b.find_first_of('+');
		
		int realA(stoi(a, &plusPosA));
		int realB(stoi(b, &plusPosB));
		int virtualA(stoi(a.substr(plusPosA + 1, a.size() - plusPosA - 2)));
		int virtualB(stoi(b.substr(plusPosB + 1, b.size() - plusPosB - 2)));
		
		int realRes(realA * realB - virtualA * virtualB);
		int virtualRes(realA * virtualB + realB * virtualA);
		return to_string(realRes) + "+" + to_string(virtualRes) + "i";
    }
};

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
};