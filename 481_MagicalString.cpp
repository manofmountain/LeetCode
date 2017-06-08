//13.85%
class Solution {
public:
   int magicalString(int n) {
    string S = "122";
    int i = 2;
    while (S.size() < n)
        S += string(S[i++] - '0', S.back() ^ 3);
    return count(S.begin(), S.begin() + n, '1');
}
};

public class Solution {
    public int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        
        int[] a = new int[n + 1];
        a[0] = 1; a[1] = 2; a[2] = 2;
        int head = 2, tail = 3, num = 1, result = 1;
        
        while (tail < n) {
            for (int i = 0; i < a[head]; i++) {
                a[tail] = num;
                if (num == 1 && tail < n) result++;
                tail++;
            }
            num = num ^ 3;
            head++;
        }
        
        return result;
    }
}

class Solution {
public:
    int magicalString(int n) {
        if (n < 2) return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        int res = 1;
        int end = 1;
        int j = 0;
        for (int i = 3; i <= n; i++) {
            if (end < i) end += dp[++j+1];
            dp[i] = j % 2 + 1;
            if (j % 2 == 0) res++;
        }
        return res;
    }
};