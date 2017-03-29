# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
##86.99%
class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        
        curr, prev = head.next, head
        while curr:
            start, prevStart = head, None
            while start.val < curr.val:
                prevStart, start = start, start.next
            if start is not curr:
                prev.next = curr.next
                if prevStart:
                    prevStart.next, curr.next = curr, start
                else:
                    head, curr.next = curr, start
                curr = prev.next
            else:
                prev, curr = curr, curr.next
        return head