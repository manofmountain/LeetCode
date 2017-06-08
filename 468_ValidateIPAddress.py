class Solution(object):
    def validIPAddress(self, IP):
        def is_hex(s):
            hex_digits = set("0123456789abcdefABCDEF")
            for char in s:
                if not (char in hex_digits):
                    return False
            return True
        ary = IP.split('.')
        if len(ary) == 4:
            for i in xrange(len(ary)):
                if not ary[i].isdigit() or not 0 <= int(ary[i]) < 256 or (ary[i][0] == '0' and len(ary[i]) > 1):
                    return "Neither"
            return "IPv4"
        ary = IP.split(':')
        if len(ary) == 8:
            for i in xrange(len(ary)):
                tmp = ary[i]
                if len(tmp) == 0 or not len(tmp) <= 4 or not is_hex(tmp):    
                    return "Neither"
            return "IPv6"
        return "Neither"

#2.53%
class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        ipv4, ipv6, neither = 'IPv4', 'IPv6', 'Neither'
        if '.' in IP:
            #Check if it's a ipv4
            ipv4List = IP.split('.')
            if len(ipv4List) != 4:
                return neither
            for ipSub in ipv4List:
                if not ipSub or len(ipSub) > 3 or len(ipSub) > 1 and ipSub[0] == '0':
                    return neither
                sum = 0
                for char in ipSub:
                    if ord(char) >= ord('0') and ord(char) <= ord('9'):
                        sum = sum * 10 + ord(char) - ord('0')
                    else:
                        return neither
                if sum > 255:
                    return neither
            return ipv4
        elif ':' in IP:
            #Check if it's a ipv6
            ipv6List = IP.split(':')
            if len(ipv6List) != 8:
                return neither
            for ipSub in ipv6List:
                if not ipSub or len(ipSub) > 4:
                    return neither
                for char in ipSub:
                    if not( ord(char) >= ord('0') and ord(char) <= ord('9') or ord(char) >= ord('a') and ord(char) <= ord('f') or ord(char) >= ord('A') and ord(char) <= ord('F')):
                        return neither
            return ipv6
        else:
            return neither
            