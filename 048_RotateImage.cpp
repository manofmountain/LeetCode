//8.81%
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len(matrix.size());
		if(len < 2)
			return;
		int startX(0), startY(0);
		while(len >= 2){
			rotateFourBorders(matrix, startX, startY, len);
			len -= 2;
			startX++;
			startY++;
		}
    }
private:
	inline void rotateFourBorders(vector<vector<int>>& matrix, int startX, int startY, int len){
		//1st Round
		for(int k = 0; k < len - 1; k++){
			swap(matrix[startX][startY + k], matrix[startX + len - k - 1][startY]);
		}
		
		//2nd Round
		for(int k = 0; k < len - 1; k++){
			swap(matrix[startX + len - k - 1][startY], matrix[startX + len - 1][startY + len - 1 - k]);
		}
		
		//3rd Round
		for(int k = 0; k < len - 1; k++){
			swap(matrix[startX + len - 1][startY + len - 1 - k], matrix[startX + k][startY + len - 1]);
		}
	}
};


//Below are from LeetCode
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}