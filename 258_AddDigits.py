class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if 0 == num:
            return 0
        if 0 == num % 9:
            return 9
        return num % 9
		
class Solution(object):
	def addDigits(self, num):
		"""
		:type num: int
		:rtype: int
		"""
		if num == 0 : return 0
		else:return (num - 1) % 9 + 1