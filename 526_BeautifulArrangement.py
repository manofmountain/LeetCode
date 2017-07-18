class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        choices = [[] for _ in xrange(N)]
        for i in xrange(1, N + 1):
            choices[i - 1].append(i)
            times = 2
            while times * i <= N:
                choices[i - 1].append(times * i)
                times += 1
            times = 2
            while i // times >= 1:
                if i % times == 0:
                    choices[i - 1].append(i // times)
                times += 1
        traced = set()
        def helper(pos):
            sum = 0
            for num in choices[pos]:
                if num not in traced:
                    traced.add(num)
                    if pos < N - 1:
                        sum += helper(pos + 1)
                    else:
                        sum += 1
                    traced.remove(num)
            return sum
        return helper(0)