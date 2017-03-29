# 19.91%
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        
        #Find first node larger than 'x'
        larger, prevLarger = head, None
        while larger and larger.val < x:
            prevLarger, larger = larger, larger.next
        
        if not larger:
            return head
        
        #Check the singly-linked list
        curr, prevCurr = larger.next, larger
        while curr:
            if curr.val < x:
                if prevLarger:
                    prevLarger.next = curr
                else:
                    head = curr
                prevCurr.next, curr.next = curr.next, larger
                prevLarger, curr = curr, prevCurr.next
            else:
                prevCurr, curr = curr, curr.next
        return head

##Wonderful solutions which uses only two nodes' space		
def partition(self, head, x):
    h1 = l1 = ListNode(0)
    h2 = l2 = ListNode(0)
    while head:
        if head.val < x:
            l1.next = head
            l1 = l1.next
        else:
            l2.next = head
            l2 = l2.next
        head = head.next
    l2.next = None
    l1.next = h2.next
    return h1.next