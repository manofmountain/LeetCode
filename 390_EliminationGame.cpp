//59.27%
class Solution {
public:
    int lastRemaining(int n) {
        int remain(n), head(1), step(1);
		bool leftToRight(true);
		while(remain > 1){
			if(leftToRight || remain % 2 == 1){
				head = head + step;
			}
			remain >>= 1;
			step <<= 1;
			leftToRight = !leftToRight;
		}
		return head;
    }
};

//A C method
/*
After first elimination, all the rest numbers are even numbers.
Divide by 2, we get a continuous new sequence from 1 to n / 2.
For this sequence we start from right to left as the first elimination.
Then the original result should be two times the mirroring result of lastRemaining(n / 2).
*/
int lastRemaining(int n) {
    return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
}

//A Java method
 public int lastRemaining(int n) {
        boolean left = true;
        int remaining = n;
        int step = 1;
        int head = 1;
        while (remaining > 1) {
            if (left || remaining % 2 ==1) {
                head = head + step;
            }
            remaining = remaining / 2;
            step = step * 2;
            left = !left;
        }
        return head;
    }
	
//Another Java method using recursive way
  public int lastRemaining(int n) {
      return leftToRight(n);
    }

    private static int leftToRight(int n) {
      if(n <= 2) return n;
      return 2 * rightToLeft(n / 2);
    }

    private static int rightToLeft(int n) {
      if(n <= 2) return 1;
      if(n % 2 == 1) return 2 * leftToRight(n / 2);
      return 2 * leftToRight(n / 2) - 1;
    }