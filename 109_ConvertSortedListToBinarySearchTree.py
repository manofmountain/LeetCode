
###96.89%
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head: return None
        if not head.next: return TreeNode(head.val)
        
        prev, fast, slow = None, head, head.next
        while slow:
            prev, fast, slow = fast, fast.next, slow.next
            if slow:
                slow = slow.next
        root = TreeNode(fast.val)
        prev.next = None
        root.left, root.right = self.sortedListToBST(head), self.sortedListToBST(fast.next)
        return root