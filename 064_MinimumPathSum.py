class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        curr = grid[m - 1][:]
        for i in range(n - 1)[::-1]:
            curr[i] += curr[i + 1]
        
        for i in range(m - 1)[::-1]:
            curr[n - 1] += grid[i][n - 1]
            for j in range(n - 1)[::-1]:
                curr[j] = min(curr[j], curr[j + 1]) + grid[i][j]
        return curr[0]

#In-place, without using extra space. quite a smart one		
def minPathSum(self, grid):
    m = len(grid)
    n = len(grid[0])
    for i in range(1, n):
        grid[0][i] += grid[0][i-1]
    for i in range(1, m):
        grid[i][0] += grid[i-1][0]
    for i in range(1, m):
        for j in range(1, n):
            grid[i][j] += min(grid[i-1][j], grid[i][j-1])
    return grid[-1][-1]