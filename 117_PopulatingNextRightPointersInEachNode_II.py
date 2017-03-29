
###92.4%
# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return
        
        pre, curr = root, None
        while pre:
            curr = pre
            while curr:
                rchild = curr.right
                if curr.left:
                    if curr.right:
                        curr.left.next = curr.right
                    else:
                        rchild = curr.left
                curr = curr.next
                while curr and not curr.left and not curr.right:
                    curr = curr.next
                if rchild and curr:
                    lchild = curr.left
                    if not curr.left:
                        lchild = curr.right
                    rchild.next = lchild
                
            while pre:
                if pre.left:
                    pre = pre.left
                    break
                elif pre.right:
                    pre = pre.right
                    break
                else:
                    pre = pre.next