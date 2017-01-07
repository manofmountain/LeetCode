# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


#Other solutions provided by LeetCode
class Solution:
    def removeNthFromEnd(self, head, n):
        def index(node):
            if not node:
                return 0
            i = index(node.next) + 1
            if i > n:
                node.next.val = node.val
            return i
        index(head)
        return head.next

class Solution:
    def removeNthFromEnd(self, head, n):
        def remove(head):
            if not head:
                return 0, head
            i, head.next = remove(head.next)
            return i+1, (head, head.next)[i+1 == n]
        return remove(head)[1]

class Solution:
    def removeNthFromEnd(self, head, n):
        fast = slow = head
        for _ in range(n):
            fast = fast.next
        if not fast:
            return head.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return head
		
#54.06%
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        def nextStep(node, n):
            '''
            Move the pointer to next node and n--.
            '''
            if node is None or n == 0:
                return node, n        
            else:
                return nextStep(node.next, n - 1)
        
        if head is None or n <= 0:
            return head
        
        #Two nodes track the node list

        nodeRet, nRet = nextStep(head, n)
        if nodeRet is None:
            if nRet == 0:
                head = head.next
            return head
        node1 = head
        while nodeRet.next is not None:
            nodeRet, node1 = nodeRet.next, node1.next
        
        node1.next = node1.next.next
        return head
        