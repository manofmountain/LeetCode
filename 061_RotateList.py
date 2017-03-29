# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or k <= 0:
            return head
        curr, size = head, 0
        while curr:
            size, curr = size + 1, curr.next
        k %= size
        if k == 0:
            return head
        index, newHead = size - k, head
        while index:
            curr, newHead, index = newHead, newHead.next, index - 1
        curr.next = None
        curr = newHead
        while curr.next: curr = curr.next
        curr.next = head
        return newHead
            