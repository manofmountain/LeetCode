# 28.6%
class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        versionList1 = map(int, version1.split('.'))
        versionList2 = map(int, version2.split('.'))
        if len(versionList1) > len(versionList2):
            versionList2 = versionList2 + ([0] * (len(versionList1) - len(versionList2)))
        elif len(versionList1) < len(versionList2):
            versionList1 = versionList1 + ([0] * (len(versionList2) - len(versionList1)))
        for ver1, ver2 in zip(versionList1, versionList2):
            if ver1 > ver2:
                return 1
            elif ver1 < ver2:
                return -1
        return 0
		
class Solution:
    # @param a, a string
    # @param b, a string
    # @return a boolean
    def compareVersion(self, version1, version2):
        v1 = version1.split('.')
        v2 = version2.split('.')
        for i in range(max(len(v1), len(v2))):
            gap = (int(v1[i]) if i < len(v1) else 0) - (int(v2[i]) if i < len(v2) else 0)
            if gap != 0:
                return 1 if gap > 0 else -1
        return 0
		
def compareVersion(self, version1, version2):
    splits = (map(int, v.split('.')) for v in (version1, version2))
    return cmp(*zip(*itertools.izip_longest(*splits, fillvalue=0)))
	
def compareVersion(self, version1, version2):
    v1, v2 = (map(int, v.split('.')) for v in (version1, version2))
    d = len(v2) - len(v1)
    return cmp(v1 + [0]*d, v2 + [0]*-d) # Wonderful magics

# A new recursive way
def compareVersion(self, version1, version2):
    main1, _, rest1 = ('0' + version1).partition('.')
    main2, _, rest2 = ('0' + version2).partition('.')
    return cmp(int(main1), int(main2)) or \
           len(rest1+rest2) and self.compareVersion(rest1, rest2)
        