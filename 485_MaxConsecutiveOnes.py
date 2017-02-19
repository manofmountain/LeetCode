class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        currCnt, maxCnt, zeroFlag = 0, 0, True
        for num in nums:
            if num == 1:
                if zeroFlag:
                    currCnt = 1
                    zeroFlag = False
                else:
                    currCnt += 1
            else:
                if not zeroFlag:
                    zeroFlag = True
                    maxCnt = max(maxCnt, currCnt)
        return max(maxCnt, currCnt)