class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if 1 > numRows:
            return []
        res = [[1]]
        for i in range(numRows - 1):
            row = [1]
            for j in range(len(res[i]) - 1):
                row.append(res[i][j] + res[i][j + 1])
            row.append(1)
            res.append(row)
        return res
# 78.48%		
# A method from LeetCode	
def generate(self, numRows):
        res = [[1]]
        for i in range(1, numRows):
            res += [map(lambda x, y: x+y, res[-1] + [0], [0] + res[-1])]
        return res[:numRows]
                
        