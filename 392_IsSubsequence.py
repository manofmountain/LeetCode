def isSubsequence(self, s, t):
    t = iter(t)
    return all(c in t for c in s)
	
from collections import defaultdict
from bisect import bisect_left
class Solution(object):
    
    def createMap(self, s):
        # create a map. key is char. value is index of apperance in acending order. 
        posMap = defaultdict(list)
        for i, char in enumerate(s):
            posMap[char].append(i)
        return posMap
        
    
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        posMap = self.createMap(t)
        # lowBound is the minimum index the current char has to be at.
        lowBound = 0
        for char in s:
            if char not in posMap: return False
            charIndexList = posMap[char]
            # try to find an index that is larger than or equal to lowBound
            i = bisect_left(charIndexList, lowBound)
            if i == len(charIndexList): return False
            lowBound = charIndexList[i] + 1
        return True