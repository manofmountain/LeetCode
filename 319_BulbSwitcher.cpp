//O(n^2)
class Solution {
public:
    int bulbSwitch(int n) {
        if(n <= 0)
			return 0;
		if(n == 1)
			return 1;
		int cnt(1);
		for(int i = 2; i <= n; ++i){
			int num(1);
			for(int j = 2; j <= i / 2; ++j){
				if(i % j == 0)
					++num;
			}
			++num; //for i itself
			if(num % 2)
				++cnt;
		}
		return cnt;
    }
};

//Turns out it's a math problem
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int bulbSwitch(int n) {
    int counts = 0;
    
    for (int i=1; i*i<=n; ++i) {
        ++ counts;    
    }
    
    return counts;
}
/*
Explanation:
A light will be toggled only during the round of its factors, e.g. number 6 light will be toggled at 1,2,3,6 and light 12 will be toggled at 1,2,3,4,6,12. The final state of a light is on and off only depends on if the number of its factor is odd or even. If odd, the light is on and if even the light is off. The number of one number's factor is odd if and only if it is a perfect square!
So we will only need to loop to find all the perfect squares that are smaller than n!
*/