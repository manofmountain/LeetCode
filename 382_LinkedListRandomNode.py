
##71.87%
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import random
class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.head = head 

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        if not self.head:
            return -1
        first = self.head
        res, size = first.val, 1
        while first.next:
            first, size = first.next, size + 1
            if random.random() <= 1.0 / size:
                res = first.val
        return res


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()