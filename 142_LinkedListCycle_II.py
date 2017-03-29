###44.75%

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return None
        fast, slow = head.next, head
        while fast:
            fast, slow = fast.next, slow.next
            if fast == slow:
                break
            if fast:
                fast = fast.next
        if not fast:
            return None
        slow = head
        while slow != fast:
            slow, fast = slow.next, fast.next
        return slow