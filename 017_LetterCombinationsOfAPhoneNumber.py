# 4.58%
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        size = len(digits)
        if size == 0:
            return list()
        mapTable = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        res = [c for c in mapTable[ord(digits[size - 1]) - ord('2')]]
        for i in range(1, size):
            res = [c + strPre for c in mapTable[ord(digits[size - i - 1]) - ord('2')] for strPre in res]
        return res

# Better solution than mine		
class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        if '' == digits: return []
        kvmaps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, [''])
        