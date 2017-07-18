def convertBST(self, root):
    def visit1(root):
        if root:
            visit1(root.left)
            vals.append(root.val)
            visit1(root.right)
    vals = []
    visit1(root)
    
    self.s = 0
    def visit2(root):
        if root:
            visit2(root.right)
            self.s += vals.pop()
            root.val = self.s
            visit2(root.left)
    visit2(root)

    return root