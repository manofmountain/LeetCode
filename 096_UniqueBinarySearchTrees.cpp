//37.15%
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1)
			return 1;
		vector<int> res(n + 1, 0);
		res[0] = 1;
		res[1] = 1;
		res[2] = 2;
		for(int total = 3; total <= n; total++){
			for(int left = 0; left < total; left++){
				res[total] += (res[left] * res[total - left - 1]);
			}
		}
		return res[n];	
    }
};

//basically the same thinking way like mine(Java solution)
public int numTrees(int n) {
    int [] G = new int[n+1];
    G[0] = G[1] = 1;
    
    for(int i=2; i<=n; ++i) {
    	for(int j=1; j<=i; ++j) {
    		G[i] += G[j-1] * G[i-j];
    	}
    }

    return G[n];
}

//We use math in this way and certainly it's better with only space complexity O(1)
//A very simple and straight ans based on Math,Catalan Number ,O(N) times,O(1)space
    int numTrees(int n) {
    //cantalan树
    //C(2n,n)/(n+1)
    long long ans =1;
    for(int i=n+1;i<=2*n;i++){
        ans = ans*i/(i-n);
    }
    return ans/(n+1);
}