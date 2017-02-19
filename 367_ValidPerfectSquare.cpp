//Newton methods
class Solution {
public:
    bool isPerfectSquare(int num) {
     long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r*r == x;
    }
};