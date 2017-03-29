//22.5%
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m(matrix.size());
		if(m == 0)
			return false;
		int n(matrix[0].size());
		if(n == 0)
			return false;
		
		int left(0), right(m * n - 1);
		while (left <= right){
			int mid((left + right) / 2);
			int rowIndex(mid / n), colIndex(mid  - rowIndex * n);
			if(matrix[rowIndex][colIndex] > target)
				right = mid - 1;
			else if(matrix[rowIndex][colIndex] < target)
				left = mid + 1;
			else
				return true;
		}
		return false;
    }
};