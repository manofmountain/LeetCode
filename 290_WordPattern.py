#62.45%
class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        map1 = dict()
        map2 = dict()
        strList = str.lstrip().strip().split(' ')
        if len(pattern) != len(strList):
            return False
        for c, str in zip(pattern, strList):
            if c in map1 and map1[c] != str or str in map2 and map2[str] != c:
                return False
            else:
                map1[c] = str
                map2[str] = c
        return True
	
# Fabulous solutions from LeetCode	
def wordPattern(self, pattern, str):
    s = pattern
    t = str.split()
    return map(s.find, s) == map(t.index, t)

# This one looks like mine but more beautiful
def wordPattern(self, pattern, str):
    f = lambda s: map({}.setdefault, s, range(len(s)))
    return f(pattern) == f(str.split())
	
def wordPattern(self, pattern, str):
    s = pattern
    t = str.split()
    return len(set(zip(s, t))) == len(set(s)) == len(set(t)) and len(s) == len(t)    