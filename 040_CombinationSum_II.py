class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def combinationSum2Helper(candidates, target, start, res, candidate):
            if not target:
                res.append(candidate[:])
                return
            i = start
            while i < size and candidates[i] <= target:
                candidate.append(candidates[i])
                combinationSum2Helper(candidates, target - candidates[i], i + 1, res, candidate)
                candidate.pop()
                i += 1
                while i < size and candidates[i] == candidates[i - 1]: i+= 1
            
        size = len(candidates)
        res = list()
        candidate = list()
        candidates.sort()
        combinationSum2Helper(candidates, target, 0, res, candidate)
        return res

# A very interesting DP solution		
def combinationSum2(self, candidates, target):
    candidates.sort()
    table = [None] + [set() for i in range(target)]
    for i in candidates:
        if i > target:
            break
        for j in range(target - i, 0, -1):
            table[i + j] |= {elt + (i,) for elt in table[j]}
        table[i].add((i,))
    return map(list, table[target])