
#beat 61.55%
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        size = len(s)
        if size <= numRows or 1 >= numRows:
            return s
        rst = ''
        strList = [""] * numRows
        flag = True
        rowIndex = 0
        for charS in s:
            strList[rowIndex] = strList[rowIndex] + charS
            if(flag):
                if(rowIndex != numRows - 1):
                    rowIndex = rowIndex + 1
                else:
                    rowIndex = rowIndex - 1
                    flag = False
            else:
                if(rowIndex):
                    rowIndex = rowIndex - 1
                else:
                    rowIndex = rowIndex + 1
                    flag = True
        
        #Add all substrings together
        for subStr in strList:
            rst = rst + subStr
            
        return rst