//22.36%
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
		int m(obstacleGrid.size()), n(obstacleGrid[0].size());
		vector<vector<int>> array(m, vector<int>(n, 0));
		int i;
		for(i = n - 1; i >= 0; i--)
			if(obstacleGrid[m - 1][i])
				break;
		for(int j = n - 1; j > i; j--)
			array[m - 1][j] = 1;
		for(i = m - 1; i >= 0; i--)
			if(obstacleGrid[i][n - 1])
				break;
		for(int j = m - 1; j > i; j--)
			array[j][n - 1] = 1;

		for(int i = m - 2; i >= 0; i--)
			for(int j = n - 2; j >= 0; j--)
				if(obstacleGrid[i][j])
					array[i][j] = 0;
				else
					array[i][j] = array[i][j + 1] + array[i + 1][j];
		return array[0][0];
    }
};

//Time O(m*n), space O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};

//Consider early stop and use space as O(m)
class Solution {
public: 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> pre(m, 0);
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                pre[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (!obstacleGrid[0][j]) {
                cur[0] = pre[0];
                if (cur[0]) flag = true; 
            }
            else cur[0] = 0;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] = cur[i - 1] + pre[i];
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0;
            }
            if (!flag) return 0;
            swap(pre, cur);
        }
        return pre[m - 1];
    }
}; 

//Use only one column, so space complexity is O(m)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                cur[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (obstacleGrid[0][j])
                cur[0] = 0;
            else flag = true;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] += cur[i - 1]; 
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0; 
            }
            if (!flag) return 0;
        }
        return cur[m - 1];
    }
};