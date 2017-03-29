# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None
##20.25%
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if not head:
            return None
        
        prev = newHead = RandomListNode(0)
        traced = dict()
        curr = head
        while curr:
            prev.next = traced[curr] = RandomListNode(curr.label)
            prev = prev.next
            curr = curr.next
        curr = head
        while curr:
            if curr.random:
                traced[curr].random = traced[curr.random]
            curr = curr.next
        return newHead.next
            