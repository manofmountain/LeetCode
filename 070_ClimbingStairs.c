//Recursive ways
int climbStairs(int n) {
    if(0 >= n)
		return 0;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	
	return climbStairs(n - 1) + climbStairs(n - 2);
}

//0.6%
//Dynamic programmings
int climbStairs(int n){
	if(0 >= n)
		return 0;

	if(1 == n)
		return 1;
	if(2 == n)
		return 2;
	
	int a = 1; //n == 1
	int b = 2; //n == 2
	for(int i = 3; i <= n; i++){
		int temp = a + b;
		a = b;
		b = temp;
	}
	return b;
}