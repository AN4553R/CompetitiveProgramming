from heapq import heappush, heapify, nlargest

class User:
    def __init__(self, id = None):
        self.id = id
        self.following = []
        self.followers = []
        self.tweets = []
    
class Tweet:
    def __new__(cls, *args, **kwargs):
        if not hasattr(cls, "order"):
            cls.order = 0
        cls.order+=1
        return super(Tweet, cls).__new__(cls)
    
    def __init__(self, id, userId):
        self.id = id
        self.userId = userId
        self.order = Tweet.order # we can replace Tweet.order with datetime.datetime.now() and remove the __new__ dunder method
        
class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.users: (int, User) = {}
        

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        tweet = Tweet(tweetId, userId)
        if userId not in self.users:
            self.users[userId] = User(userId)    
        usr = self.users[userId]
        usr.tweets.append(tweet)
        

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        wall = []
        if userId in self.users:    
            for tweet in self.users[userId].tweets:
                heappush(wall, (tweet.order, tweet.id))
            for f in self.users[userId].following:
                for tweet in self.users[f].tweets:
                    heappush(wall, (tweet.order, tweet.id))
            newsFeed = nlargest(10, wall)
            return [tweet[1] for tweet in newsFeed]

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId not in self.users:
            self.users[followerId] = User(followerId)
        if followeeId not in self.users:
            self.users[followeeId] = User(followeeId)
        
        if followeeId not in self.users[followerId].following:
            self.users[followerId].following.append(followeeId)
            
        if followerId not in self.users[followeeId].followers:
            self.users[followeeId].followers.append(followerId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        if followeeId in self.users and followerId in self.users:
            if followerId in self.users[followeeId].followers:
                self.users[followeeId].followers.remove(followerId)
            if followeeId in self.users[followerId].following:
                self.users[followerId].following.remove(followeeId)
        
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
