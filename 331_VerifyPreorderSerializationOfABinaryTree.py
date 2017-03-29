###49.1%
class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        nodeList = preorder.split(',')
        diff = 1
        for node in nodeList:
            diff -= 1
            if diff < 0: return False
            if node != '#': diff += 2
        return diff == 0