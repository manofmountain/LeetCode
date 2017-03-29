class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        if m == 0:
            return
        n = len(matrix[0])
        if n == 0:
            return
        
        rows, cols = set(), set()
        for i in xrange(m):
            for j in xrange(n):
                if(matrix[i][j] == 0):
                    rows.add(i)
                    cols.add(j)
        for row in rows:
            matrix[row] = [0] * n
        for col in cols:
            for rowList in matrix:
                rowList[col] = 0