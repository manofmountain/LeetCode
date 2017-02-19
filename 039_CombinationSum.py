# 34.3%
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def combinationSumHelper(candidates, left, target):
            res = list()
            i = left
            while i < size:
                first = candidates[i]
                times = 1
                while first < target:
                    subRes = combinationSumHelper(candidates, i + 1, target - first)
                    if subRes:
                        for subList in subRes:
                            j = 0
                            while j < times:
                                subList.append(candidates[i])
                                j += 1
                            res.append(subList)
                    first += candidates[i]
                    times += 1
                if first == target:
                    subRes = [candidates[i]] * times
                    res.append(subRes)
                i += 1
            return res
                
        size = len(candidates)
        if 0 == size:
            return list()
        return combinationSumHelper(candidates, 0, target)
        