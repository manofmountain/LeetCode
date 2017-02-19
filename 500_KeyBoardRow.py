# 96.02%
class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row1 = ['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p']
        row2 = ['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l']
        row3 = ['z', 'x', 'c', 'v', 'b', 'n', 'm']
        table = dict()
        for c in row1:
            table[c] = 0
        for c in row2:
            table[c] = 1
        for c in row3:
            table[c] = 2
        #size1, size2, size3 = 10, 9, 7
        res = list()
        #currRow = -1
        for word in words:
            flag = True
            c = word[0]
            if c >= 'A' and c <= 'Z':
                c = chr(ord(c) - ord('A') + ord('a'))
            currRow = table[c]
            for c in word[1:]:
                if c >= 'A' and c <= 'Z':
                    c = chr(ord(c) - ord('A') + ord('a'))
                tempRow = table[c]
                if tempRow != currRow:
                    flag = False
                    break
            if flag:
                res.append(word)
        return res
 # By using regex to check it
 # Here (?i) and the 'i' means ignore alphabet upper / lower case
 
 ##Here we know this little knowledge
 #(?i) starts case-insensitive mode
#(?-i) turns off case-insensitive mode
 def findWords(self, words):
    return filter(re.compile('(?i)([qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*)$').match, words)           