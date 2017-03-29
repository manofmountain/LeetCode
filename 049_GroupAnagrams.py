class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = list()
        indexTable = {}
        index = 0
        for str in strs:
            keyStr = ''.join(sorted(str))
            if keyStr not in indexTable:
                res.append([str])
                indexTable[keyStr] = index
                index += 1
            else:
                res[indexTable[keyStr]].append(str)
        return res
		