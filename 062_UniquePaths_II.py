class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        dim1 = len(obstacleGrid)
        if dim1 == 0:
            return 0
        dim2 = len(obstacleGrid[0])
        if dim2 == 0:
            return 0
        i = dim1 - 1
        array = [[0]* dim2 for _ in range(dim1)]
        m, n = dim1, dim2
        while i >= 0:
            if obstacleGrid[i][n - 1] == 1:
                break
            i -= 1
        i += 1
        while i < dim1:
            array[i][n - 1] = 1
            i += 1
        i = dim2 - 1
        while i >= 0:
            if obstacleGrid[m - 1][i] == 1:
                break
            i -= 1
        i += 1
        while i < dim2:
            array[m - 1][i] = 1
            i += 1
            
        for i in range(m - 1)[::-1]:
            for j in range(n - 1)[::-1]:
                if obstacleGrid[i][j] == 1:
                    array[i][j] = 0
                else:
                    array[i][j] = array[i + 1][j] + array[i][j + 1]
        return array[0][0]