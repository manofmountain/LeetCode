class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0
        
        q = [endWord]
        dist = 2
        while q:
            newQ = list()
            for candidate in q:
                if candidate == beginWord:
                    return dist
                dist += 1
                wordSet.discard(candidate)     
                for i in xrange(len(candidate)):
                    for j in xrange(26):
                        choice = candidate[:i] + chr(ord('a') + j) + candidate[i + 1:]
                        if choice in wordSet:
                            newQ.append(choice)
            q = newQ
        return 0
		

###A deque solution		
from collections import deque
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        
        def construct_dict(word_list):
            d = {}
            for word in word_list:
                for i in range(len(word)):
                    s = word[:i] + "_" + word[i+1:]
                    d[s] = d.get(s, []) + [word]
            return d
            
        def bfs_words(begin, end, dict_words):
            queue, visited = deque([(begin, 1)]), set()
            while queue:
                word, steps = queue.popleft()
                if word not in visited:
                    visited.add(word)
                    if word == end:
                        return steps
                    for i in range(len(word)):
                        s = word[:i] + "_" + word[i+1:]
                        neigh_words = dict_words.get(s, [])
                        for neigh in neigh_words:
                            if neigh not in visited:
                                queue.append((neigh, steps + 1))
            return 0
        
        d = construct_dict(wordList | set([beginWord, endWord]))
        return bfs_words(beginWord, endWord, d)
                