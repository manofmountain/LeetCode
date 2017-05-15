def removeKdigits(self, num, k):
    out = []
    for d in num:
        while k and out and out[-1] > d:
            out.pop()
            k -= 1
        out.append(d)
    return ''.join(out[:-k or None]).lstrip('0') or '0'
	
def removeKdigits(self, num, k):
    sub = re.compile('1[0]|2[01]|3[0-2]|4[0-3]|5[0-4]|6[0-5]|7[0-6]|8[0-7]|9[0-8]|.$').sub
    for _ in range(k):
        num = sub(lambda m: m.group()[1:], num, 1)
    return num.lstrip('0') or '0'