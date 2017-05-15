//97.71%
class Solution {
public:
    int getMoneyAmount(int n) {
		if(n == 1)
			return 0;
		if(n == 2)
			return 1;
		if(n == 3)
			return 2;
		if(n == 4)
			return 4;
		vector<vector<int> > res(n, vector<int>(n, INT_MAX));
		//l == 1
		for(int i = 1; i <= n; ++i)
			res[i - 1][i - 1] = 0;
		//l == 2
		for(int i = 1; i <= n - 1; ++i)
			res[i - 1][i] = i;
		
		
		//l == 3
		for(int i = 1; i <= n - 2; ++i)
			res[i - 1][i + 1] = i + 1;
		
		
		//l == 4
		for(int i = 1; i <= n - 3; ++i)
			res[i - 1][i + 2] = i * 2 + 2;
		
		
		for(int l = 5; l <= n; ++l){
			for(int i = 1; i <= n - l + 1; ++i){
				for(int j = i + l / 2; j < i + l - 1; ++j){
					res[i - 1][i + l - 2] = min(res[i - 1][i + l - 2], j + max(res[i - 1][j - 2], res[j][i + l - 2]));
				}
			}
		}
		return res[0][n - 1];	
    }
};

//A java solution which is more concise
public class Solution {
    public int getMoneyAmount(int n) {
        int[][] table = new int[n+1][n+1];
        return DP(table, 1, n);
    }
    
    int DP(int[][] t, int s, int e){
        if(s >= e) return 0;
        if(t[s][e] != 0) return t[s][e];
        int res = Integer.MAX_VALUE;
        for(int x=s; x<=e; x++){
            int tmp = x + Math.max(DP(t, s, x-1), DP(t, x+1, e));
            res = Math.min(res, tmp);
        }
        t[s][e] = res;
        return res;
    }
}

//An iterative way
public class Solution {
    public int getMoneyAmount(int n) {
        int[][] table = new int[n+1][n+1];
        for(int j=2; j<=n; j++){
            for(int i=j-1; i>0; i--){
                int globalMin = Integer.MAX_VALUE;
                for(int k=i+1; k<j; k++){
                    int localMax = k + Math.max(table[i][k-1], table[k+1][j]);
                    globalMin = Math.min(globalMin, localMax);
                }
                table[i][j] = i+1==j?i:globalMin;
            }
        }
        return table[1][n];
    }
}