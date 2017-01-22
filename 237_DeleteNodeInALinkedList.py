# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        if node and node.next:
            while node.next:
                node.val = node.next.val
                pre, node = node, node.next
            pre.next = None

def deleteNode(self, node):
    node.val = node.next.val
    node.next = node.next.next
