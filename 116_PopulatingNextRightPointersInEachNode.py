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
        if not root.right:
            self.connect(root.left)
            return
        self.connect(root.left)
        self.connect(root.right)
        lchild, rchild = root.left, root.right
        while rchild:
            lchild.next = rchild
            lchild, rchild = lchild.right, rchild.left

##40.2%			
class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return
        pre, curr = root, None
        while pre.left:
            curr = pre
            while curr:
                curr.left.next = curr.right
                if curr.next:
                    curr.right.next = curr.next.left
                curr = curr.next
            pre = pre.left