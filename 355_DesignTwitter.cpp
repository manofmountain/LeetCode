//81.61%
//int Twitter::timeStamp = 0;
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter():timeStamp(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		if(postTweets.find(userId) == postTweets.end()){
			postTweets.insert(make_pair(userId, vector<pair<int, int> >()));
			if(relationTable.find(userId) == relationTable.end()){
				relationTable.insert(make_pair(userId, unordered_set<int>()));
				relationTable[userId].insert(userId);
			}
		}
		postTweets[userId].push_back(make_pair(timeStamp++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
		if(relationTable.find(userId) == relationTable.end())
			return {};
		typedef unordered_set<int>::iterator setIterator;
        vector<int> res;
		unordered_map<int, int> pointers;
		priority_queue<pair<pair<int, int>, int> > heap;
		
		for(setIterator ite = relationTable[userId].begin(); ite != relationTable[userId].end(); ++ite){
			int buddy(*ite);
			pointers.insert(make_pair(buddy, 0));
			if(pointers[buddy] < postTweets[buddy].size()){
				int tweetIndex(postTweets[buddy].size() - 1);
				heap.push(make_pair(postTweets[buddy][tweetIndex], buddy));
			}
		}
		
		while(res.size() < 10 && !heap.empty()){
			res.push_back(heap.top().first.second);
			int buddy(heap.top().second);
			heap.pop();
			if(++pointers[buddy] < postTweets[buddy].size()){
				int tweetIndex(postTweets[buddy].size() - pointers[buddy] - 1);
				heap.push(make_pair(postTweets[buddy][tweetIndex], buddy));
			}
		}
		return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
		if(relationTable.find(followerId) == relationTable.end()){
			relationTable.insert(make_pair(followerId, unordered_set<int>()));
			relationTable[followerId].insert(followerId);
		}
        relationTable[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
		if(relationTable.find(followerId) == relationTable.end() || followerId == followeeId)
			return;
		relationTable[followerId].erase(followeeId);
    }
private:
	int timeStamp;
	unordered_map<int, unordered_set<int> > relationTable;
	unordered_map<int, vector<pair<int, int> > > postTweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
 
 //Another solution using C++
 class Twitter
{
    struct Tweet
    {
        int time;
        int id;
        Tweet(int time, int id) : time(time), id(id) {}
    };

    std::unordered_map<int, std::vector<Tweet>> tweets; // [u] = array of tweets by u
    std::unordered_map<int, std::unordered_set<int>> following; // [u] = array of users followed by u

    int time;

public:
    Twitter() : time(0) {}

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].emplace_back(time++, tweetId);
    }

    std::vector<int> getNewsFeed(int userId)
    {
        std::vector<std::pair<Tweet*, Tweet*>> h; // pair of pointers (begin, current)

        for (auto& u: following[userId])
        {
            auto& t = tweets[u];
            if (t.size() > 0)
                h.emplace_back(t.data(), t.data() + t.size() - 1);
        }
        auto& t = tweets[userId]; // self
        if (t.size() > 0)
            h.emplace_back(t.data(), t.data() + t.size() - 1);

        auto f = [](const std::pair<Tweet*, Tweet*>& x, const std::pair<Tweet*, Tweet*>& y) {
            return x.second->time < y.second->time;
        };
        std::make_heap(h.begin(), h.end(), f);

        const int n = 10;
        std::vector<int> o;
        o.reserve(n);
        for (int i = 0; (i < n) && !h.empty(); ++i)
        {
            std::pop_heap(h.begin(), h.end(), f);

            auto& hb = h.back();
            o.push_back(hb.second->id);

            if (hb.first == hb.second--)
                h.pop_back();
            else
                std::push_heap(h.begin(), h.end(), f);
        }
        return o;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};