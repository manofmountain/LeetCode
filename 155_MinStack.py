# 94.64%
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.minStack = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.stack.append(x)
        if not self.minStack or self.minStack[-1] >= x:
            self.minStack.append(x)

    def pop(self):
        """
        :rtype: void
        """
        if not self.stack:
            return
        last = self.stack.pop()
        if self.minStack[-1] == last:
            self.minStack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        if not self.stack:
            return
        return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if not self.minStack:
            return
        return self.minStack[-1]

# A better solution than mine from LeetCode which use only one stack list
def __init__(self):
    """
    initialize your data structure here.
    """
    self.stack= []

def push(self, x):
    """
    :type x: int
    :rtype: nothing
    """
    if not self.stack:self.stack.append((x,x)) 
    else:
       self.stack.append((x,min(x,self.stack[-1][1])))

def pop(self):
    """
    :rtype: nothing
    """
    if self.stack: self.stack.pop()

def top(self):
    """
    :rtype: int
    """
    if self.stack: return self.stack[-1][0]
    else: return None

def getMin(self):
    """
    :rtype: int
    """
    if self.stack: return self.stack[-1][1]
    else: return None
# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()