class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "0"
        mask, step, sizeInt = 0xf, 4, 8
        i = 0
        res = ""
        largeDigits = ['a', 'b', 'c', 'd', 'e', 'f']
        while i < sizeInt and num != 0:
            temp = num & mask
            if temp < 10:
                res += str(temp)
            else:
                res += largeDigits[temp - 10]
            num >>= step
            i += 1
        return res[::-1]