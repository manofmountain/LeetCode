# bfs + queue
def binaryTreePaths2(self, root):
    if not root:
        return []
    res, queue = [], collections.deque([(root, "")])
    while queue:
        node, ls = queue.popleft()
        if not node.left and not node.right:
            res.append(ls+str(node.val))
        if node.left:
            queue.append((node.left, ls+str(node.val)+"->"))
        if node.right:
            queue.append((node.right, ls+str(node.val)+"->"))
    return res

# dfs + stack
def binaryTreePaths1(self, root):
    if not root:
        return []
    res, stack = [], [(root, "")]
    while stack:
        node, ls = stack.pop()
        if not node.left and not node.right:
            res.append(ls+str(node.val))
        if node.right:
            stack.append((node.right, ls+str(node.val)+"->"))
        if node.left:
            stack.append((node.left, ls+str(node.val)+"->"))
    return res
# dfs recursively
def binaryTreePaths(self, root):
    if not root:
        return []
    res = []
    self.dfs(root, "", res)
    return res

def dfs(self, root, ls, res):
    if not root.left and not root.right:
        res.append(ls+str(root.val))
    if root.left:
        self.dfs(root.left, ls+str(root.val)+"->", res)
    if root.right:
        self.dfs(root.right, ls+str(root.val)+"->", res)
# A solution from LeetCode
def binaryTreePaths(self, root):
    if not root:
        return []
    return [str(root.val) + '->' + path
            for kid in (root.left, root.right) if kid
            for path in self.binaryTreePaths(kid)] or [str(root.val)]

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# I couldn't make it at last, this is a failure one
class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        def binaryTreePathsHelper(res, base, node):
            #if not node:
            #    return
            base.append(str(node.val))
            if not node.left and not node.right:
                res.append('->'.join(base))
                base = base.pop()
                return
            if node.left:
                binaryTreePathsHelper(res, base, node.left)
                base.pop()
            if node.right:
                binaryTreePathsHelper(res, base, node.right)
                base.pop()
            
        res = []
        if not root: return res
        base = [str(root.val)]
        if not root.left and not root.right:
            res.append(base[0])
            return res
        if root.left:
            binaryTreePathsHelper(res, base, root.left)
            base.pop()
        if root.right:
            binaryTreePathsHelper(res, base, root.right)
            #base.pop()
        return res
        