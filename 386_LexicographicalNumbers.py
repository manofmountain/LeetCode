class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = list()
        curr = 1
        for i in xrange(n):
            res.append(curr)
            if curr * 10 <= n:
                curr *= 10
            else:
                if curr == n:
                    curr /= 10
                curr += 1
                while curr % 10 == 0:
                    curr /= 10
        return res
                    
                    
class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def dfs(val):
            if val > n:
                return
            else:
                res.append(val)
                for i in xrange(10):
                    if val * 10 + i > n:
                        return
                    dfs(val * 10 + i)
        res = list()
        for val in xrange(1, 10):
            dfs(val)
        return res