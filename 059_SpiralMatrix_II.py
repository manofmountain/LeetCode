def generateMatrix(self, n):
    A = [[0] * n for _ in range(n)]
    i, j, di, dj = 0, 0, 0, 1
    for k in xrange(n*n):
        A[i][j] = k + 1
        if A[(i+di)%n][(j+dj)%n]:
            di, dj = dj, -di
        i += di
        j += dj
    return A
# Can not work
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n <= 0:
            return list()
        subRes = range(n)
        res = [subRes for i in range(n)]
        up, down, left, right = 0, n - 1, 0, n - 1
        index = 1
        while True:
            #Up
            for col in xrange(left, right + 1):
                res[up][col] = index
                index += 1
            up += 1
            if up > down: break
            
            #Right
            for row in xrange(up, down + 1):
                res[row][right] = index
                index += 1
            right -= 1
            if right < left: break
            
            #Down
            for col in (range(left, right + 1))[::-1]:
                res[down][col] = index
                index += 1
            down -= 1
            if down < up: break
            
            #Left
            for row in (range(up, down + 1))[::-1]:
                res[row][left] = index
                index += 1
            left += 1
            if left > right: break
        return res
        
        