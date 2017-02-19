#23%
import collections
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        counter = collections.Counter(s)
        for i in range(len(s)):
            if counter[s[i]] == 1:
                return i
        return -1
		
class Solution(object):
    def firstUniqChar(self, s):
        return min([s.find(c) for c in string.ascii_lowercase if s.count(c)==1] or [-1])
		
class Solution(object):
    def firstUniqChar(self, s):
        return min([s.find(c) for c,v in collections.Counter(s).iteritems() if v==1] or [-1])