class Solution {
public:
    double myPow(double x, int n) {		
        if(n < 0){
			double y = myPow(x, n / 2);
			if(n % 2)
				y  = y * y * (1 / x);
			else
				y = y * y;
			return y;
		}
		
		if(n == 0)
			return 1;
		double y = myPow(x, n / 2);
		if(n & 1)
			return y * y * x;
		else	
			return y * y;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        //基数为1，-1, 0，可以特殊处理
        //if(x == 1)return 1.0;
        //else if(x == -1)return n%2 ? -1.0 : 1.0;
        //else if(x == 0)return 0.0;
        double res = 1.0;
        //使用long long主要防止n = -2147483648时，取反溢出
        long long nn = n;
        if(nn < 0)
            nn = -nn;
        while(nn != 0)
        {
            if(nn & 1)
                res *= x;
            nn >>= 1;
            x *= x;
        }
        if(n > 0)
            return res;
        else return 1/res;
    }
};

public class Solution {
    public double pow(double x, int n) {
        if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
}

double myPow(double x, int n) {
    if(n<0) return 1/x * myPow(1/x, -(n+1));
    if(n==0) return 1;
    if(n==2) return x*x;
    if(n%2==0) return myPow( myPow(x, n/2), 2);
    else return x*myPow( myPow(x, n/2), 2);
}

double myPow(double x, int n) { 
    if(n==0) return 1;
    double t = myPow(x,n/2);
    if(n%2) return n<0 ? 1/x*t*t : x*t*t;
    else return t*t;
}

double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0){
        n = -n;
        x = 1/x;
    }
    return n%2==0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
}

double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0) {
        n = -n;
        x = 1/x;
    }
    double ans = 1;
    while(n>0){
        if(n&1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}