//A concise Java solution
public class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return new int[0];
        int m = matrix.length, n = matrix[0].length;
        
        int[] result = new int[m * n];
        int row = 0, col = 0, d = 0;
        int[][] dirs = {{-1, 1}, {1, -1}};
        
        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];
            row += dirs[d][0];
            col += dirs[d][1];
            
            if (row >= m) { row = m - 1; col += 2; d = 1 - d;}
            if (col >= n) { col = n - 1; row += 2; d = 1 - d;}
            if (row < 0)  { row = 0; d = 1 - d;}
            if (col < 0)  { col = 0; d = 1 - d;}
        }
        
        return result;
    }
}

//Another thinking way
public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix.length == 0) return new int[0];
        int r = 0, c = 0, m = matrix.length, n = matrix[0].length, arr[] = new int[m * n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = matrix[r][c];
            if ((r + c) % 2 == 0) { // moving up
                if      (c == n - 1) { r++; }
                else if (r == 0)     { c++; }
                else            { r--; c++; }
            } else {                // moving down
                if      (r == m - 1) { c++; }
                else if (c == 0)     { r++; }
                else            { r++; c--; }
            }   
        }   
        return arr;
}

//60.75%
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
			return {};
		
		const int left(0), right(matrix[0].size() - 1), up(0), down(matrix.size() - 1);
		
		//Boundary conditions
		if(up == down)
			return matrix[0];
		if(left == right){
			vector<int> res(down + 1);
			for(int i = up; i <= down; ++i)
				res[i] = matrix[i][0];
			return res;
		}
		
		int i(0), j(0), index(0);
		vector<int> res;
		//res.reserve((right + 1) * (down + 1));
		bool direction(true);
		while(i < down || j < right){
			res.push_back(matrix[i][j]);
			if(up == i){
				//From right, top  To left, down
				if(direction){
					if(j == right)
						++i;
					else
						++j;
					direction = !direction;
				//From left, down to right, top
				}else{
					++i;
					--j;
				}
			}else if(right == j){
				if(direction){
					++i;
					direction = !direction;
				}else{
					++i;
					--j;
				}	
			}else if(left == j){
				if(direction){
					--i;
					++j;
				}else{
					if(i == down)
						++j;
					else
						++i;
					direction = !direction;
				}
			}else if(down == i){
				if(direction){
					--i;
					++j;
				}else{
					++j;
					direction = !direction;
				}
			}else{
				if(direction){
					--i;
					++j;
				}else{
					++i;
					--j;
				}
			}
			//++index;
			//if(index > 10)
			//	break;
		}
		res.push_back(matrix[down][right]);
		return res;				
    }
};