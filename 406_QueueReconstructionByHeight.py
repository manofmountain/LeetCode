##54.57%

#Pick out tallest group of people and sort them in a subarray (S). Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.
#For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.
#E.g.
#input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
#subarray after step 1: [[7,0], [7,1]]
#subarray after step 2: [[7,0], [6,1], [7,1]]
#...

#It's not the most concise code, but I think it well explained the concept.

class Solution(object):
    def reconstructQueue(self, people):
        if not people: return []

        # obtain everyone's info
        # key=height, value=k-value, index in original array
        peopledct, height, res = {}, [], []
        
        for i in xrange(len(people)):
            p = people[i]
            if p[0] in peopledct:
                peopledct[p[0]] += (p[1], i),
            else:
                peopledct[p[0]] = [(p[1], i)]
                height += p[0],

        height.sort()      # here are different heights we have

        # sort from the tallest group
        for h in height[::-1]:
            peopledct[h].sort()
            for p in peopledct[h]:
                res.insert(p[0], people[p[1]])

        return res
		
		
def reconstructQueue(self, people):
    people.sort(key=lambda (h, k): (-h, k))
    queue = []
    for p in people:
        queue.insert(p[1], p)
    return queue