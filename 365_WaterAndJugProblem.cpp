class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
		if(!z)
			return true;
		if(z > x + y)
			return false;
        if(x > y)
			return canMeasureWater(y, x, z);
		if(!x)
			return z == y;
		int remainY(y % x);
		int remainX(x - remainY);
		queue<int> q;
		unordered_set<int> traced;
		q.push(remainY);
		q.push(remainX);
		traced.insert(0);
		while(!q.empty()){
			int choice(q.front());
			q.pop();
			if(choice == z || choice + x == z || choice + y == z)
				return true;
			traced.insert(choice);
			int newChoice((choice + x) % y);
			if(traced.find(newChoice) == traced.end())
				q.push(newChoice);
			newChoice = (choice + y) % x;
			if(traced.find(newChoice) == traced.end())
				q.push(newChoice);
		}
		return false;		
    }
};


//Turns out it's a math problem
/*
Forget about two jugs pouring between each other, which may make you confused.

Let's make it simple: assuming we have one big enough bucket and two cups with volume x and y, respectively. Now we want to perform a series of operation -- pouring water in and out only by those two cups with exactly amount x or y. Somehow, there will be only z water left in this big bucket eventually. Then the equation will be:

z = m * x + n * y
m means using cup-x m times. If m is positive, it means pouring in. Otherwise, it's pouring out.
n is similar.

For example, 4 = (-2) * 3 + 2 * 5, which means you pour in water twice with cup-5 and pour out water twice with cup-3. Talk back to the question, it's like we first fill jug-5, pour water to jug-3 from jug-5, empty jug-3, pour the remaining 2 water into jug-3 from jug-5, fill jug-5 again, pour water into jug-3 from jug-5, empty jug-3, then we have only 4 water left in jug-5. It's exactly fill jug-5 twice and empty jug-3 twice.

Now the question is, can we find those two m and n exist?

The answer is YES. Here we need a little math -- Bezout's identity, which is:

We can always find a and b to satisfy ax + bx = d where d = gcd(x, y)

So, everything is clear, if z % d == 0, then we have (a*z/d)*x + (b*z/d)*y = z, which means m and n exist.

Below is the code:
*/
public boolean canMeasureWater(int x, int y, int z) {
    //limit brought by the statement that water is finallly in one or both buckets
    if(x + y < z) return false;
    //case x or y is zero
    if( x == z || y == z || x + y == z ) return true;
    
    //get GCD, then we can use the property of Bézout's identity
    return z%GCD(x, y) == 0;
}

public int GCD(int a, int b){
    while(b != 0 ){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}


bool canMeasureWater(int x, int y, int z) {
    return z == 0 || z <= (long long)x + y && z % __gcd(x, y) == 0;
}