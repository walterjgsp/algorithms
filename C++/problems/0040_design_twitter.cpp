// Problem Statement
// Design a simplified version of Twitter where users can post tweets,
// follow/unfollow another user and is able to see the 10 most recent tweets in the
// user's news feed. Your design should support the following methods:
//
// postTweet(userId, tweetId): Compose a new tweet.
// getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed.
// Each item in the news feed must be posted by users who the user followed or by
//  the user herself. Tweets must be ordered from most recent to least recent.
// follow(followerId, followeeId): Follower follows a followee.
// unfollow(followerId, followeeId): Follower unfollows a followee.
// Example:
//
// Twitter twitter = new Twitter();
//
// // User 1 posts a new tweet (id = 5).
// twitter.postTweet(1, 5);
//
// // User 1's news feed should return a list with 1 tweet id -> [5].
// twitter.getNewsFeed(1);
//
// // User 1 follows user 2.
// twitter.follow(1, 2);
//
// // User 2 posts a new tweet (id = 6).
// twitter.postTweet(2, 6);
//
// // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.getNewsFeed(1);
//
// // User 1 unfollows user 2.
// twitter.unfollow(1, 2);
//
// // User 1's news feed should return a list with 1 tweet id -> [5],
// // since user 1 is no longer following user 2.
// twitter.getNewsFeed(1);
#include <bits/stdc++.h>

using namespace std;

class Twitter {
private:
    unordered_map<int,set<int>> connections;
    vector<pair<int,int>> tweets;
public:
    /** Initialize your data structure here. */
    Twitter() {
        connections = unordered_map<int,set<int>> ();
        tweets = vector<pair<int,int>>();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(connections.find(userId)==connections.end()){
            connections[userId] = set<int>();
        }

        tweets.push_back(make_pair(userId,tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        int index = tweets.size()-1;
        while(index>=0 && newsFeed.size()<10){
            if(tweets[index].first == userId || connections[userId].find(tweets[index].first)!=connections[userId].end()){
                newsFeed.push_back(tweets[index].second);
            }
            index--;
        }

        return newsFeed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        connections[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(connections.find(followerId)!=connections.end()){
            connections[followerId].erase(followeeId);
        }
    }
};

void printVec(const vector<int> &vec){
  for(auto val : vec)
    cout<<val<<" ";
  cout<<endl;
}

int main(){
  Twitter twitter;
  twitter.postTweet(1, 5);
  printVec(twitter.getNewsFeed(1));
  twitter.follow(1, 2);
  twitter.postTweet(2, 6);
  printVec(twitter.getNewsFeed(1));
  twitter.unfollow(1, 2);
  printVec(twitter.getNewsFeed(1));
  return 0;
}
