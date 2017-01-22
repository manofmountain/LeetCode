# Can not get this out
class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        cows = bulls = 0
		dictMap = dict()
        for s,g in zip(secret, guess):
			if s == g:
				cow += 1
			else:
				if s in dictMap:
					dictMap[s] += 1
				else:
					dictMap[s] = 0
				if g in dictMap:
					dictMap[g] -= 1
				else:
					dictMap[g] = 0
				if dictMap[g] >= 0:
					bulls += 1
				if dictMap[s] < 0:
					bulls += 1
        bulls -= cows
        return str(cows) + 'A' + str(bulls) + 'B'
		
	# A good solution from LeetCode	
    s, g = Counter(secret), Counter(guess)
    a = sum(i == j for i, j in zip(secret, guess))
    return '%sA%sB' % (a, sum((s & g).values()) - a)

# Another one	
def getHint(self, secret, guess):
    bulls = sum(map(operator.eq, secret, guess))
    both = sum(min(secret.count(x), guess.count(x)) for x in '0123456789')
    return '%dA%dB' % (bulls, both - bulls)
	
class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bulls = 0
        l1, l2 = [0]*10, [0]*10
        nums1, nums2 = map(int, secret), map(int, guess)
        length = len(secret)
        for i in xrange(length):
            if nums1[i] == nums2[i]:
                bulls += 1
            else:
                l1[nums1[i]] += 1
                l2[nums2[i]] += 1
        cows = sum(map(min, zip(l1,l2)))
        return '%dA%dB' % (bulls, cows)