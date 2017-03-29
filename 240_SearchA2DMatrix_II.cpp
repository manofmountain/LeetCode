//mlog(n) 
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
return searchMatrix(matrix, target, 0, matrix.size() - 1);
 }

 bool searchMatrix(vector<vector<int>>& matrix, int target, int top, int bottom) {
if (top > bottom)
	return false;

int mid = top + (bottom - top) / 2;
if (matrix[mid].front() <= target && target <= matrix[mid].back())
	if (searchVector(matrix[mid], target)) return true;

if (searchMatrix(matrix, target, top, mid - 1)) return true;
if (searchMatrix(matrix, target, mid + 1, bottom)) return true;

return false;
 }

 bool searchVector(vector<int>& v, int target) {
int left = 0, right = v.size() - 1;

while (left <= right) {
	int mid = left + (right - left) / 2;
	if (v[mid] == target)
		return true;
	if (v[mid] < target)
		left = mid + 1;
	else
		right = mid - 1;
}

return false;
 }
 
 
 //O(m + n)
 //75.1%
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
 int i = 0;
 int j = matrix[0].size() - 1;
 
 while(i < matrix.size() && j >= 0) {
     if(matrix[i][j] == target)
         return true;
     
     if(matrix[i][j] < target)
         i++;
     else
         j--;
 }
 
 return false;
 }

//17.76%
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
			return false;
		int left(0), right(matrix[0].size() - 1), up(0), down(matrix.size() - 1);
		while(left <= right && up <= down){
			int l(left), r(right);
			while(l <= r){
				int mid(l + (r - l) / 2);
				if(matrix[up][mid] == target)
					return true;
				else if(matrix[up][mid] < target)
					l = mid + 1;
				else
					r = mid - 1;
			}
			++up;
			int u(up), d(down);
			while(u <= d){
				int mid(u + (d - u) / 2);
				if(matrix[mid][left] == target)
					return true;
				else if(matrix[mid][left] < target)
					u = mid + 1;
				else
					d = mid - 1;
			}
			++left;
		}
		return false;
    }
};

//16.09%
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
			return false;
		return searchMatrixHelper(matrix, 0, 0, matrix.size(), matrix[0].size(), target);
    }
private:
	bool searchMatrixHelper(const vector<vector<int> >& matrix, int startX, int startY, int rows, int cols, int target){
		if(rows == 0 || cols == 0)
			return false;
		int left(startY), right(startY + cols - 1);
		while(left <= right){
			int mid(left + (right - left) / 2);
			if(matrix[startX][mid] == target)
				return true;
			else if(matrix[startX][mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		int up(startX), down(startX + rows - 1);
		while(up <= down){
			int mid(up + (down - up) / 2);
			if(matrix[mid][startY] == target)
				return true;
			else if(matrix[mid][startY] < target)
				up = mid + 1;
			else
				down = mid - 1;
		}
		return searchMatrixHelper(matrix, startX + 1, startY + 1, rows - 1, cols - 1, target);
	}
};

