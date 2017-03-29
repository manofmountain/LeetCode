//33.14%
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		if(n <= 0){
			vector<vector<int>> temp;
			return temp;
		}
		
        vector<int> vec(n);
		vector<vector<int>> res(n, vec);
		int up(0), down(n - 1), left(0), right(n - 1);
		int index(1);
		while(true){
			//up
			for(int col = left; col <= right; col++)
				res[up][col] = index++;
			if(++up > down) break;
			//right
			for(int row = up; row <= down; row++)
				res[row][right] = index++;
			if(--right < left) break;
			//down
			for(int col = right; col >= left; col--)
				res[down][col] = index++;
			if(--down < up) break;
			//left
			for(int row = down; row >= up; row--)
				res[row][left] = index++;
			if(++left > right) break;
		}
		return res;
    }
};