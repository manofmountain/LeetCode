# 39.49%
import collections
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        mCounter = collections.Counter(magazine)
        #rCounter = collections.Counter(ransomNote)
        for c in ransomNote:
            if c not in mCounter or mCounter[c] == 0:
                return False
            mCounter[c] -= 1
        return True

# Wonderful use on python		
def canConstruct(self, ransomNote, magazine):
    return not collections.Counter(ransomNote) - collections.Counter(magazine)
	
	#or use it in this direct way
	c = Counter(magazine)
    c.subtract(Counter(ransomNote))
    return all(v >= 0 for v in c.values())