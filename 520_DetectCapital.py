#82.51%
class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        cnt = 0
        for c in word:
            if c.isupper():
                cnt += 1
        return cnt == 0 or cnt == len(word) or cnt == 1 and word[0].isupper()
		
	def detectCapitalUse(self, word):
		return word.isupper() or word.islower() or word.istitle()