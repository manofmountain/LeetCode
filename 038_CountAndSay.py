
def countAndSay(self, n):
    s = '1'
    for _ in range(n - 1):
        s = ''.join(str(len(list(group))) + digit
                    for digit, group in itertools.groupby(s))
    return s

def countAndSay(self, n):
    s = '1'
    for _ in range(n - 1):
        s = ''.join(str(len(group)) + digit
                    for group, digit in re.findall(r'((.)\2*)', s))
    return s

#Method from LeetCode
def countAndSay(self, n):
    s = '1'
    for _ in range(n - 1):
        s = re.sub(r'(.)\1*', lambda m: str(len(m.group(0))) + m.group(1), s)
    return s
#65.14%
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if 1 > n:
            return ""
        if 1 == n:
            return "1"
        rst = ""
        prev = self.countAndSay(n - 1)
        prev = prev + '#'
        prevChar = prev[0]
        times = 1
        for c in prev[1:]:
            if c == prevChar:
                times = times + 1
            else:
                rst = rst + str(times)
                rst = rst + prevChar
                prevChar = c
                times = 1
        
        return rst
        
                