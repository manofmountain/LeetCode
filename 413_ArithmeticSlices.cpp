//16.0%
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
			return 0;
		
		int res(0), start(0), diff(A[1] - A[0]);
		int i(2);
		for(; i < A.size(); ++i){
			if(A[i] - A[i - 1] != diff){
				if(i - start >= 3)
					res += combinationNums(i - start);
				start = i - 1;
				diff = A[i] - A[i - 1];
			}
		}
		if(A[i - 1] - A[i - 2] == diff){
			if(i - start >= 3)
				res += combinationNums(i - start);
		}
		return res;
    }
private:
	int combinationNums(int num){
		return (num - 1) * (num - 2) / 2;
	}
};

//16.73%
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
			return 0;
		
		int res(0), start(0), diff(A[1] - A[0]);
		int i(2);
		for(; i < A.size(); ++i){
			if(A[i] - A[i - 1] != diff){
				if(i - start >= 3){
					int num(i - start);
					res += (num - 1) * (num - 2) / 2;
				}
				start = i - 1;
				diff = A[i] - A[i - 1];
			}
		}
		if(A[i - 1] - A[i - 2] == diff){
			if(i - start >= 3){
				int num(i - start);
				res += (num - 1) * (num - 2) / 2;
			}
		}
		return res;
    }
};

//Java solution -- A dynamic programming method
public int numberOfArithmeticSlices(int[] A) {
    int curr = 0, sum = 0;
    for (int i=2; i<A.length; i++)
        if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
            curr += 1;
            sum += curr;
        } else {
            curr = 0;
        }
    return sum;
}