class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        strList = []
        while n:
            strList.append(chr((n - 1) % 26 + ord('A')))
            n = (n - 1) / 26
        strList.reverse()
        return "".join(strList)
		

return "" if num == 0 else self.convertToTitle((num - 1) / 26) + chr((num - 1) % 26 + ord('A'))