# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return False
        fast, slow = head.next, head
        while fast:
            fast = fast.next
            slow = slow.next
            if slow is fast:
                return True
            if fast:
                fast = fast.next
        return False

# A noive solution from LeetCode which use the 'exception' in a genious way		
def hasCycle(self, head):
    try:
        slow = head
        fast = head.next
        while slow is not fast:
            slow = slow.next
            fast = fast.next.next
        return True
    except:
        return False
		
def hasCycle(self, head):
    slow = fast = head
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
        if slow == fast:
            return True
    return False