class Twitter(object):

    def __init__(self):
        self.timer = itertools.count(step=-1)
        self.tweets = collections.defaultdict(collections.deque)
        self.followees = collections.defaultdict(set)

    def postTweet(self, userId, tweetId):
        self.tweets[userId].appendleft((next(self.timer), tweetId))

    def getNewsFeed(self, userId):
        tweets = heapq.merge(*(self.tweets[u] for u in self.followees[userId] | {userId}))
        return [t for _, t in itertools.islice(tweets, 10)]

    def follow(self, followerId, followeeId):
        self.followees[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        self.followees[followerId].discard(followeeId)c
		


###Another solution		
import heapq

class Twitter(object):

    def __init__(self):
        self.time = 0
        self.tweets = {}
        self.followee = {}
        

    def postTweet(self, user, tweet):
        self.time += 1
        self.tweets[user] = self.tweets.get(user, []) + [(-self.time,  tweet)]
        
        

    def getNewsFeed(self, user):
        h, tweets = [], self.tweets
        people = self.followee.get(user, set()) | set([user])
        for person in people:
            if person in tweets and tweets[person]:
                time, tweet = tweets[person][-1]
                h.append((time, tweet, person, len(tweets[person]) - 1))
        heapq.heapify(h)
        news = []
        for _ in range(10):
            if h:
                time, tweet, person, idx = heapq.heappop(h)
                news.append(tweet)
                if idx:
                    new_time, new_tweet = tweets[person][idx-1]
                    heapq.heappush(h, (new_time, new_tweet, person, idx - 1))
        return news
        
        

    def follow(self, follower, other):
        self.followee[follower] = self.followee.get(follower, set()) | set([other])
        
        

    def unfollow(self, follower, other):
        if follower in self.followee:
            self.followee[follower].discard(other)