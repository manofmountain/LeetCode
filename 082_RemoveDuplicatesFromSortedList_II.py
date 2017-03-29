
###24.95%
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        
        orig, curr = head, head
        while curr.next and curr.val == curr.next.val:
            curr = curr.next
        
        if curr == orig:
            curr.next = self.deleteDuplicates(curr.next)
        else:
            return self.deleteDuplicates(curr.next)
        return curr