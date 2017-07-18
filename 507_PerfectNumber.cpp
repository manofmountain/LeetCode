//19.98%
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1)
			return false;
		int sum(1), start(2);
		
		//Find out all its prime dividors and their counter
		map<int, int> primeCounter;
		while(start <= sqrt(num)){
			if(num % start == 0){
				sum += start;
				if(num / start != start)
					sum += num / start;
			}			
			++start;
		}
		return num == sum;
    }
};

//A java solution
public class Solution {
    public boolean checkPerfectNumber(int num) {
        if (num == 1) return false;
        
        int sum = 0;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) sum += num / i;
            }
        }
        sum++;
        
        return sum == num;
    }
}

//Better solution(as a square numbers are NOT perfect number.)
public bool CheckPerfectNumber(int num) {
        if (num < 2) return false;
        int sum = 1;
        for (int x = 2; x * x <= num; x++)
        {
            if (num % x == 0)
            {
                sum += x;
                sum += num / x;
            }
        }
        
        return sum == num;
}


public boolean checkPerfectNumber(int num) {
    int sum = 1;
    for (int i=2;i<Math.sqrt(num);i++) 
        if (num % i == 0) sum += i + (num/i == i ? 0 : num/i);
    return num != 1 && sum == num;
}

class Solution {
public:
    bool checkPerfectNumber(int num) {
        static unordered_set<int> n = {6, 28, 496, 8128, 33550336};
        return n.count(num);
    }
};