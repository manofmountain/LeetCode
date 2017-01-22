class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s = list()
        

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.s.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        #self.s = self.s[1:]
        del self.s[0]

    def peek(self):
        """
        :rtype: int
        """
        return self.s[0]

    def empty(self):
        """
        :rtype: bool
        """
        return not len(self.s)
        