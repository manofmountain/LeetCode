//44.16%
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> rowVec(n);
		vector<vector<int>> array(m, rowVec);
		array[m - 1][n - 1] = 0;
		for(int i = 0; i < m; i++)
			array[i][n - 1] = 1;
		for(int i = 0; i < n; i++)
			array[m - 1][i] = 1;
		for(int i = m - 2; i >= 0; i--)
			for(int j = n - 2; j >= 0; j--)
				array[i][j] = array[i + 1][j] + array[i][j + 1];
		return array[0][0];
    }
};

//A good one from LeetCode
//1st: Showed me this way to initialize a two-dimension vector elegantly
//2nd: Just don't initialize 'm - 1' row and 'n - 1' col specifically like I did	
class Solution {
    int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};

//Use only O(min(m, n)) space
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m); 
        vector<int> pre(m, 1);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++)
                cur[i] = cur[i - 1] + pre[i];
            swap(pre, cur);
        }
        return pre[m - 1];
    }
};

//Use only one vector of O(min(m, n))
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
}; 

//A mathematical way to do this with only O(1) space
//Total permutations = (m+n)! / (m! * n!)
public class Solution {
    public int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        m--;
        n--;
        if(m < n) {              // Swap, so that m is the bigger number
            m = m + n;
            n = m - n;
            m = m - n;
        }
        long res = 1;
        int j = 1;
        for(int i = m+1; i <= m+n; i++, j++){       // Instead of taking factorial, keep on multiply & divide
            res *= i;
            res /= j;
        }
            
        return (int)res;
    }
}