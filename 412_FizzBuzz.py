class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        i, res = 1, list()
        while i <= n:
            item = ""
            if i % 3 == 0:
                item += "Fizz"
            if i % 5 == 0:
                item += "Buzz"
            if item == "":
                item += str(i)
            res.append(item)
            i += 1
        return res
		
def fizzBuzz(self, n):
    return ['Fizz' * (not i % 3) + 'Buzz' * (not i % 5) or str(i) for i in range(1, n+1)]