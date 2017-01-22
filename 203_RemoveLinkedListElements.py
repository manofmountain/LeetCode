# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# 29.83%
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        while head and head.val == val: head = head.next
        pre = head
        while pre:
            while pre.next and pre.next.val == val:
                pre.next = pre.next.next
            pre = pre.next
        return head