# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# 55%
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        first, curr, pre, count = head, head, None, 0
        while curr:
            count += 1
            curr = curr.next
        count -= (count / 2)
        
        #Separate two parts
        curr = head
        while count:
            pre, curr, count = curr, curr.next, count - 1
        if pre: pre.next = None
        
        #Reverse second half part
        pre = None
        while curr:
            pre, curr.next, curr = curr, pre, curr.next
        
        #Compare two parts
        while first and pre:
            if first.val != pre.val:
                return False
            first, pre = first.next, pre.next
        return True
		
 # Better solution than mine      
 def isPalindrome(self, head):
    rev = None
    slow = fast = head
    while fast and fast.next:
        fast = fast.next.next
        rev, rev.next, slow = slow, rev, slow.next
    if fast:
        slow = slow.next
    while rev and rev.val == slow.val:
        slow = slow.next
        rev = rev.next
    return not rev      

# Same principle and keep input list as original
def isPalindrome(self, head):
    rev = None
    fast = head
    while fast and fast.next:
        fast = fast.next.next
        rev, rev.next, head = head, rev, head.next
    tail = head.next if fast else head
    isPali = True
    while rev:
        isPali = isPali and rev.val == tail.val
        head, head.next, rev = rev, head, rev.next
        tail = tail.next
    return isPali	