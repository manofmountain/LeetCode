##79.01%
class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return 1
        res, sign = [nums[0]], 0
        for num in nums[1:]:
            if num > res[-1]:
                if sign > 0:
                    res[-1] = num
                else:
                    res.append(num)
                    sign = 1
            elif num < res[-1]:
                if sign < 0:
                    res[-1] = num
                else:
                    res.append(num)
                    sign = -1
        return len(res)

##Python solution which is concise		
def wiggleMaxLength(self, nums):
    nan = float('nan')
    diffs = [a-b for a, b in zip([nan] + nums, nums + [nan]) if a-b]
    return sum(not d*e >= 0 for d, e in zip(diffs, diffs[1:]))


###What a genious. ^_^..@@	
#Alternative implementations not using the nan trick: First remove repetitions, then count the local extrema except the ends, and add the number of #ends (because the ends are always local extrema)

def wiggleMaxLength(self, nums):
    norep = [num for num, _ in itertools.groupby(nums)]
    triples = zip(norep, norep[1:], norep[2:])
    return sum((b>a) == (b>c) for a, b, c in triples) + len(norep[:2])

def wiggleMaxLength(self, nums):
    norep = [num for num, _ in itertools.groupby(nums)]
    if len(norep) < 2: return len(norep)
    triples = zip(norep, norep[1:], norep[2:])
    return 2 + sum(a<b>c or a>b<c for a, b, c in triples)
        