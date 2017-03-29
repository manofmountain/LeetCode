#53.65
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        addedStr = dict()
        res = []
        for i in xrange(len(s) - 9):
            if s[i:i + 10] in addedStr:
                if addedStr[s[i: i + 10]] == 1:
                    res.append(s[i:i + 10])
                addedStr[s[i : i + 10]] += 1
            else:
                addedStr[s[i : i + 10]] = 1
        return res
        
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        addedStr = dict()
        for i in xrange(len(s) - 9):
            if s[i:i + 10] in addedStr:
                addedStr[s[i : i + 10]] += 1
            else:
                addedStr[s[i : i + 10]] = 1
        return [item[0] for item in addedStr.items() if item[-1] > 1]