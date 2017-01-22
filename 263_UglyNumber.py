class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        while num and num % 5 == 0:
            num /= 5
        while num and num % 3 == 0:
            num /= 3
        while num and num % 2 == 0:
            num /= 2
        return 1 == num

for p in 2, 3, 5:
    while num % p == 0 < num:
        num /= p
return num == 1