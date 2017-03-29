class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = list()
        for token in tokens:
            if token == "+":
                if len(stack) >= 2:
                    stack[-2] += stack[-1]
                    stack.pop()
                else:
                    return 0
            elif token == "-":
                if len(stack) >= 2:
                    stack[-2] -= stack[-1]
                    stack.pop()
                else:
                    return 0
            elif token == "*":
                if len(stack) >= 2:
                    stack[-2] *= stack[-1]
                    stack.pop()
                else:
                    return 0
            elif token == "/":
                if len(stack) >= 2:
                    stack[-2] = int(float(stack[-2]) / float(stack[-1]))
                    stack.pop()
                else:
                    return 0
            else:
                stack.append(int(token))
        return stack[-1] if stack else 0
                    