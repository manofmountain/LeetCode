###68.3%
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = list()
        num = 0
        sign = '+'
        s += '+'
        for c in s:
            if c.isdigit():
                num = num * 10 + (ord(c) - ord('0'))
            if not c.isdigit() and c != ' ':
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack[-1] *= num
                elif sign == '/':
                    stack[-1] = int(float(stack[-1]) / float(num))
                sign = c
                num = 0
        #stack.append(num)
        return sum(stack)