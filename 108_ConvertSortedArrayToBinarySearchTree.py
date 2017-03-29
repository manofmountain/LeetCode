##27.18%
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def sortedArrayToBST(left, right):
            if left > right:
                return None
            if left == right:
                return TreeNode(nums[left])
            mid = (left + right) / 2
            root = TreeNode(nums[mid])
            root.left, root.right = sortedArrayToBST(left, mid - 1), sortedArrayToBST(mid + 1, right)
            return root
        return sortedArrayToBST(0, len(nums) - 1)