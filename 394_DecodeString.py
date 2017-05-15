##74.31%
class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        def decodeStringHelper(index):
            res = str()
            num = 0
            while index[0] < len(s) and s[index[0]] != ']':
                if s[index[0]].isdigit():
                    num = 0
                    while s[index[0]].isdigit():
                        num = num * 10 + ord(s[index[0]]) - ord('0')
                        index[0] += 1
                    index[0] += 1 # remove '['
                    subRes = decodeStringHelper(index)
                    res += subRes * num
                    index[0] += 1 # remove ']'
                else:
                    res += s[index[0]]
                    index[0] += 1
            return res
        return decodeStringHelper([0])
		
class Solution(object):
    def decodeString(self, s):
        stack = []
        stack.append(["", 1])
        num = ""
        for ch in s:
            if ch.isdigit():
              num += ch
            elif ch == '[':
                stack.append(["", int(num)])
                num = ""
            elif ch == ']':
                st, k = stack.pop()
                stack[-1][0] += st*k
            else:
                stack[-1][0] += ch
        return stack[0][0]
                
def decodeString(self, s):
    while '[' in s:
        s = re.sub(r'(\d+)\[([a-z]*)\]', lambda m: int(m.group(1)) * m.group(2), s)
    return s