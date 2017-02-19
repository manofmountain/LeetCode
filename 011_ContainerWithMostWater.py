class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height) - 1
        maxRes = -1
        while left < right:
            if height[left] > height[right]:
                lower = height[right]
                maxRes = max(lower * (right - left), maxRes)
                while height[right] <= lower:
                    right -= 1
            else:
                lower = height[left]
                maxRes = max(lower * (right - left), maxRes)
                while left != right and height[left] <= lower:
                    left += 1
        return maxRes
                
                