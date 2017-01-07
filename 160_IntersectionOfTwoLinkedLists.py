# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# 57.1%
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return None
        currA, currB = headA, headB
        flagA, flagB = 0, 0
        while currA is not currB:
            if not currA.next:
                if not flagA:
                    flagA = 1
                    currA = headB
                else:
                    return None
            else:
                currA = currA.next
                
            if not currB.next:
                if not flagB:
                    flagB = 1
                    currB = headA
                else:
                    return None
            else:
                currB = currB.next
        return currA
		

# better solution from LeetCode Discuss		
 # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        if headA is None or headB is None:
            return None

        pa = headA # 2 pointers
        pb = headB

        while pa is not pb:
            # if either pointer hits the end, switch head and continue the second traversal, 
            # if not hit the end, just move on to next
            pa = headB if pa is None else pa.next
            pb = headA if pb is None else pb.next

        return pa # only 2 ways to get out of the loop, they meet or the both hit the end=None