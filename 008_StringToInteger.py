
#74.06%
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        rst = 0
        #Remove left space characters
        str = str.lstrip()
        if not len(str):
            return 0
        #Check first character
        #True as 'positive', False as 'Negative'
        flag = (-1) if str[0] == '-' else 1
        if str[0] == '+' or str[0] == '-':
            startIndex = 1
        else:
            startIndex = 0
        
        INT_MAX = 0x7fffffff
        INT_MIN = 0 - 0x80000000
        #Main routine
        for eachChar in str[startIndex:]:
            if eachChar.isdigit():
                rst = rst * 10 + int(eachChar)
                rstVal = rst * flag
                if rstVal >= INT_MAX:
                    return INT_MAX
                elif rstVal <= INT_MIN:
                    return INT_MIN
            else:
                break
        
        return rst * flag
        
        
        
        