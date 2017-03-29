# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
##23.13%
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow, fast = slow.next, fast.next.next
        secondHalf = self.sortList(slow.next)
        slow.next = None
        firstHalf = self.sortList(head)
        
        newHead = ListNode(0)
        prev = newHead
        while firstHalf and secondHalf:
            if firstHalf.val < secondHalf.val:
                prev.next, firstHalf = firstHalf, firstHalf.next
            else:
                prev.next, secondHalf = secondHalf, secondHalf.next
            prev = prev.next
        if firstHalf:
            prev.next = firstHalf
        elif secondHalf:
            prev.next = secondHalf
        return newHead.next
		
        