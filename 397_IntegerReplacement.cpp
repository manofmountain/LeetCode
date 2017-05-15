//Memory limit excedeed
class Solution {
public:
    int integerReplacement(int n) {
		if(1 == n)
			return 0;
		int mark(0);
		if(n == INT_MAX){
			n = INT_MAX - 1;
			mark = 1;
		}
        vector<int> records(n + 1, -1);
		records[0] = 0;
		return mark + integerReplacementHelper(n, records);
    }
private:
	int integerReplacementHelper(int n, vector<int>& records){
		if(records[n - 1] != -1)
			return records[n - 1];
		if(n & 1){
			records[n - 1] = 1 + min(integerReplacementHelper(n - 1, records), integerReplacementHelper(n + 1, records));
		}else
			records[n - 1] = 1 + integerReplacementHelper(n / 2, records);
		return records[n - 1];
	}
};

//27.58%
class Solution {
public:
    int integerReplacement(int n) {
		if(1 == n)
			return 0;
		
		if(n == INT_MAX){
			return integerReplacement(n - 1);
		}
		
        if(n & 1){
			return 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
		}else
			return 1 + integerReplacement(n / 2);
	}
};

//91.6%
class Solution {
public:
    int integerReplacement(int n) {
		int cnt(0);
		if(n == INT_MAX)
			return 32;
		while(n != 1){
			++cnt;
			if((n & 1) == 0)
				n /= 2;
			else if(n == 3 || (n & 2) == 0)
				--n;
			else
				++n;
		}
		return cnt;
	}
};

//A java iterative solution
public int integerReplacement(int n) {
    int c = 0;
    while (n != 1) {
        if ((n & 1) == 0) {
            n >>>= 1;
        } else if (n == 3 || Integer.bitCount(n + 1) > Integer.bitCount(n - 1)) {
            --n;
        } else {
            ++n;
        }
        ++c;
    }
    return c;
}

public int integerReplacement(int n) {
    int c = 0;
    while (n != 1) {
        if ((n & 1) == 0) {
            n >>>= 1;
        } else if (n == 3 || ((n >>> 1) & 1) == 0) {
            --n;
        } else {
            ++n;
        }
        ++c;
    }
    return c;
}

public int integerReplacement(int n) {
    if(n==Integer.MAX_VALUE) return 32; //n = 2^31-1;
    int count = 0;
    while(n>1){
        if(n%2==0) n/=2;
        else{
            if((n+1)%4==0&&(n-1!=2)) n++;
            else n--;
        }
        count++;
    }
    return count;
}

public class Solution {
    public int integerReplacement(int n) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        map.put(1, 0);
        map.put(2, 1);

        return helper(n, map);
    }
    
    private int helper(int n, Map<Integer, Integer> map) {
        if (map.containsKey(n)) {
            return map.get(n);
        }
        
        int steps = -1;
        if (n % 2 == 0) {
            steps = helper(n / 2, map) + 1;
        } else {
            steps = Math.min(helper((n - 1), map) + 1, helper(1 + (n - 1) / 2, map) + 2);
        }
        
        map.put(n, steps);
        
        return steps;
    }
}