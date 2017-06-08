##65.48%
class Solution(object):
    def magicalString(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        if n <= 3:
            return 1
        numList = [1, 2, 2]
        head, res, tail = 2, 1, 1
        while len(numList) < n:
            numList.extend([tail] * numList[head])
            if tail == 1: res += numList[head]
            tail ^= 3
            head += 1
        if len(numList) > n and numList[-1] == 1:
            res -= 1
        return res
		
		
def magicalString(self, n):
    def gen():
        for x in 1, 2, 2:
            yield x
        for i, x in enumerate(gen()):
            if i > 1:
                for _ in range(x):
                    yield i % 2 + 1
    return sum(x & 1 for x in itertools.islice(gen(), n))