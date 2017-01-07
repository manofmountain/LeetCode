
#Solution from LeetCode
class Solution:
    # @return a boolean
    def isValid(self, s):
        stack = []
        dict = {"]":"[", "}":"{", ")":"("}
        for char in s:
            if char in dict.values():
                stack.append(char)
            elif char in dict.keys():
                if stack == [] or dict[char] != stack.pop():
                    return False
            else:
                return False
        return stack == []

#45.4%
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        strMap = {}
        strMap[')'] = '('
        strMap['}'] = '{'
        strMap[']'] = '['
        
        valueList = ['(', '{', '[']
        keyList = [')', '}', ']']
        strList = []
        for str in s:
            if str in keyList:
                if len(strList) == 0 or strMap[str] != strList.pop():
                    return False
            elif str in valueList:
                strList.append(str)
            else:
                return False
        
        if len(strList) == 0:
            return True
        return False