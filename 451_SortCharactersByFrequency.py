##32.25%
from collections import Counter

class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return s
        c = Counter(s)
        records = c.items()
        records.sort(key = lambda x: x[1], reverse = True)
        return ''.join([val[0] * val[1] for val in records])
        