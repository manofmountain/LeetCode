class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        res = list()
        for findNum in findNums:
            for i, num in enumerate(nums):
                flag = False
                if num == findNum:
                    for after in nums[i + 1:]:
                        if after > findNum:
                            res.append(after)
                            flag = True
                            break
                    if not flag:
                        res.append(-1)
        return res
                    
  def nextGreaterElement(self, findNums, nums):
    return [next((y for y in nums[nums.index(x):] if y > x), -1) for x in findNums]                      