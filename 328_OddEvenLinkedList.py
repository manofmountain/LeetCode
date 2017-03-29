# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
###72.01%
class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        evenHead = ListNode(0)
        currOdd, currEven = head, head.next
        evenHead.next = currEven
        while currEven:
            currOdd.next = currEven.next
            if currOdd.next:
                currOdd = currOdd.next
            else:
                currOdd.next = evenHead.next
                return head
            currEven.next = currOdd.next
            currEven = currEven.next
        currOdd.next = evenHead.next
        return head