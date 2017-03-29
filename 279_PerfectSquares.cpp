class Solution {
public:
    int numSquares(int n) {
		if(0 == n)
			return 0;
		
		int factor(sqrt(n));
		int cnt(n);
		while(factor){
			int remain = n - factor * factor;
			if(remain == 0)
				return 1;
			if(!records[remain])
				records[remain] = numSquares(remain);
			cnt = min(cnt, 1 + records[remain]);
			--factor;
		}
		return cnt;
    }
private:
    static vector<int> records(n);
};

class Solution {
public:
    int numSquares(int n) {
		if(0 == n)
			return 0;
		int factor(sqrt(n));
		int cnt(n);
		while(factor){
			int remain = n - factor * factor;
			if(remain == 0)
				return 1;
			if(records.find(remain) == records.end())
				records[remain] = numSquares(remain);
			cnt = min(cnt, 1 + records[remain]);
			--factor;
		}
		return cnt;
    }
private:
	unordered_map<int, int> records;
};

//22.56%
//Dynamic programming
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Note that cntPerfectSquares[0] is 0.
        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++)
            {
                cntPerfectSquares[i] = 
                    min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
            }
        }
        
        return cntPerfectSquares.back();
    }
};

//Static programmings
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Since cntPerfectSquares is a static vector, if 
        // cntPerfectSquares.size() > n, we have already calculated the result 
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});
        
        // While cntPerfectSquares.size() <= n, we need to incrementally 
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            
            cntPerfectSquares.push_back(cntSquares);
        }
        
        return cntPerfectSquares[n];
    }
};