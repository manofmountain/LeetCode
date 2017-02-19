# This is my method and it's too slow
class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
        i, j = 0, len(s) - 1
        while i < j:
            while i < j and s[i] not in vowels:
                i += 1
            while i < j and s[j] not in vowels:
                j -= 1
            if i < j:
                s = s[:i] + s[j] + s[i + 1 : j] + s[i] + s[j + 1:]
                i += 1
                j -= 1
        return s

# A good way		
def reverseVowels(self, s):
    vowels = re.findall('(?i)[aeiou]', s)
    return re.sub('(?i)[aeiou]', lambda m: vowels.pop(), s)
	
def reverseVowels(self, s):
    vowels = (c for c in reversed(s) if c in 'aeiouAEIOU')
    return re.sub('(?i)[aeiou]', lambda m: next(vowels), s)