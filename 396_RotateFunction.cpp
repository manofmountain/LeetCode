//32.92%
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.size() <= 1)
			return 0;
		if(A.size() == 2)
			return max(A[0], A[1]);
		
		int sum(0), res(0), currRes(0), size(A.size());
		for(int i = 0; i < size; ++i){
			res += (i * A[i]);
			sum += A[i];
		}
		currRes = res;
		for(int i = size - 1; i > 0; --i){
			currRes += (sum - A[i] * size);
			res = max(res, currRes);
		}
		return res;
    }
};