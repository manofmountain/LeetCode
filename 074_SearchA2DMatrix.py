#84.3%
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        if n == 0:
            return False
        
        left, right = 0, m * n - 1
        while left <= right:
            mid = (left + right) / 2
            rowIndex = mid / n
            colIndex = mid - rowIndex * n
            if matrix[rowIndex][colIndex] > target:
                right = mid - 1
            elif matrix[rowIndex][colIndex] < target:
                left = mid + 1
            else:
                return True
        return False