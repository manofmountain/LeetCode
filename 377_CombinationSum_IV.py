##50.83%
class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        def combinationSum4Helper(value):
            if value in table:
                return table[value]
            sum = 0
            for num in nums:
                if value > num:
                    if value - num not in table:
                        table[value - num] = combinationSum4Helper(value - num)
                    sum += table[value - num]
                elif value == num:
                    sum += 1
            return sum
                    
        table = {}
        return combinationSum4Helper(target)

#Concise DP solution		
class Solution(object):
    def combinationSum4(self, nums, target):
        nums, combs = sorted(nums), [1] + [0] * (target)
        for i in range(target + 1):
            for num in nums:
                if num  > i: break
                if num == i: combs[i] += 1
                if num  < i: combs[i] += combs[i - num]
        return combs[target]

##This one is like mine		
class Solution(object):
    def combinationSum4WithLength(self, nums, target, length, memo=collections.defaultdict(int)):
        if length <= 0: return 0
        if length == 1: return 1 * (target in nums)
        if (target, length) not in memo: 
            for num in nums:
                memo[target, length] += self.combinationSum4(nums, target - num, length - 1)
        return memo[target, length]