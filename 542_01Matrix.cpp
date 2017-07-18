//32.29%
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m(matrix.size()), n(matrix[0].size());
		int step(0);
		queue<pair<int, int>> q;
		vector<vector<bool>> traced(m, vector<bool>(n));
		//Traced all '0' elements
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				if(matrix[i][j] == 0){
					q.push(make_pair(i, j));
					traced[i][j] = true;
				}
		q.push(make_pair(-1, -1));
		++step;
		while(q.size() > 1){
			auto front(q.front());
			q.pop();
			int i(front.first), j(front.second);
			if(i == -1){
				++step;
				q.push(make_pair(i, j));
				continue;
			}
			//Up
			if(i - 1 >= 0 && !traced[i - 1][j]){
				matrix[i - 1][j] = step;
				q.push(make_pair(i - 1, j));
				traced[i - 1][j] = true;
			}
			//down
			if(i + 1 < m && !traced[i + 1][j]){
				matrix[i + 1][j] = step;
				q.push(make_pair(i + 1, j));
				traced[i + 1][j] = true;
			}
			//Left
			if(j - 1 >= 0 && !traced[i][j - 1]){
				matrix[i][j - 1] = step;
				q.push(make_pair(i, j - 1));
				traced[i][j - 1] = true;
			}
			//Right
			if(j + 1 < n && !traced[i][j + 1]){
				matrix[i][j + 1] = step;
				q.push(make_pair(i, j + 1));
				traced[i][j + 1] = true;
			}
		}
		return matrix;
    }		
};

//A BFS method with the same thinking of mine
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int> > q;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
                q.push({ i, j }); //Put all 0s in the queue.
            }

    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
            if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                    dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                    q.push({ new_r, new_c });
                }
            }
        }
    }
    return dist;
}

//A DP solution
/*
Intuition

The distance of a cell from 0 can be calculated if we know the nearest distance for all the neighbours, in which case the distance is minimum distance of any neightbour + 1. And, instantly, the word come to mind DP!!
For each 1, the minimum path to 0 can be in any direction. So, we need to check all the 4 direction. In one iteration from top to bottom, we can check left and top directions, and we need another iteration from bottom to top to check for right and bottom direction.

Algorithm

Iterate the matrix from top to bottom-left to right:
Update \text{dist}[i][j]=\min(\text{dist}[i][j],\min(\text{dist}[i][j-1],\text{dist}[i-1][j])+1)dist[i][j]=min(dist[i][j],min(dist[i][j−1],dist[i−1][j])+1) i.e., minimum of the current dist and distance from top or left neighbour +1, that would have been already calculated previously in the current iteration.
Now, we need to do the back iteration in the similar manner: from bottom to top-right to left:
Update \text{dist}[i][j]=\min(\text{dist}[i][j],\min(\text{dist}[i][j+1],\text{dist}[i+1][j])+1)dist[i][j]=min(dist[i][j],min(dist[i][j+1],dist[i+1][j])+1) i.e. minimum of current dist and distances calculated from bottom and right neighbours, that would be already available in current iteration.
*/
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

    //First pass: check for left and top
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0)
                dist[i][j] = 0;
            else {
                if (i > 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j > 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }

    //Second pass: check for bottom and right
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (i < rows - 1)
                dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            if (j < cols - 1)
                dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
        }
    }

    return dist;
}