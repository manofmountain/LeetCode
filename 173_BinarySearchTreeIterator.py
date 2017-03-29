# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
##24.37%
class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self._array = list()
        self._currIndex = 0
        if not root:
            return
        stack = list()
        curr = root
        while stack or curr:
            if curr:
                if curr.left:
                    stack.append(curr)
                    curr = curr.left
                else:
                    self._array.append(curr.val)
                    curr = curr.right
            else:
                curr = stack.pop()
                self._array.append(curr.val)
                curr = curr.right

    def hasNext(self):
        """
        :rtype: bool
        """
        return self._currIndex < len(self._array)
        

    def next(self):
        """
        :rtype: int
        """
        self._currIndex += 1
        return self._array[self._currIndex - 1]
        

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
###Clearly a better solution
class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.stack = list()
        self.pushAll(root)

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return self.stack

    # @return an integer, the next smallest number
    def next(self):
        tmpNode = self.stack.pop()
        self.pushAll(tmpNode.right)
        return tmpNode.val
        
    def pushAll(self, node):
        while node is not None:
            self.stack.append(node)
            node = node.left