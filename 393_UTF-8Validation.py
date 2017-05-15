##95.29%
class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        if not data:
            return True
        cnt = 0
        for val in data:
            if val & 0x80 == 0:
                if cnt != 0:
                    return False
            elif val & 0x40 == 0:
                if cnt == 0:
                    return False
                cnt -= 1
            else:
                if cnt > 0:
                    return False
                flag, cnt = 0x20, 1
                while val & flag != 0:
                    cnt += 1
                    flag >>= 1
                    if cnt > 3:
                        return False
        return cnt == 0