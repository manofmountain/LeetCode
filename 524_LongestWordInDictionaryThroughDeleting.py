def findLongestWord(self, s, d):
    def isSubsequence(x):
        it = iter(s)
        return all(c in it for c in x)
    return min(filter(isSubsequence, d) + [''], key=lambda x: (-len(x), x))
	
#Optimized as suggested by @easton042, testing from longest to shortest and returning the first valid one without testing the rest:
def findLongestWord(self, s, d):
    def isSubsequence(x):
        it = iter(s)
        return all(c in it for c in x)
    d.sort(key=lambda x: (-len(x), x))
    return next(itertools.ifilter(isSubsequence, d), '')
	
def findLongestWord(self, s, d):
    for x in sorted(d, key=lambda x: (-len(x), x)):
        it = iter(s)
        if all(c in it for c in x):
            return x
    return ''
	
#And taking that even further by not sorting unnecessarily much:
def findLongestWord(self, s, d):
    heap = [(-len(word), word) for word in d]
    heapq.heapify(heap)
    while heap:
        word = heapq.heappop(heap)[1]
        it = iter(s)
        if all(c in it for c in word):
            return word
    return ''