class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        currLen, maxLen = 0, 0
        startIndex = 0
        map = dict()
        for i, c in enumerate(s):
            if c not in map:
                map[c] = i
                currLen += 1
            else:
                if currLen > maxLen:
                    maxLen = currLen
                endIndex = map[c]
                temp = endIndex
                for j in range(startIndex, endIndex + 1):
                    del map[s[j]]
                startIndex = temp + 1
                map[c] = i
                currLen = i - temp
        return max(currLen, maxLen)
		
class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        start = maxLength = 0
        usedChar = {}
        
        for i in range(len(s)):
            if s[i] in usedChar and start <= usedChar[s[i]]:
                start = usedChar[s[i]] + 1
            else:
                maxLength = max(maxLength, i - start + 1)

            usedChar[s[i]] = i

        return maxLength