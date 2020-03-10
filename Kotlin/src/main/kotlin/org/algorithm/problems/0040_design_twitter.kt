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
package org.algorithm.problems

class Twitter {

    /** Initialize your data structure here. */
    val users:HashMap<Int,HashSet<Int>> = HashMap<Int,HashSet<Int>>();
    val feedList:MutableList<Pair<Int,Int>> = mutableListOf<Pair<Int,Int>>();

    /** Compose a new tweet. */
    fun postTweet(userId: Int, tweetId: Int) {
        if(!users.containsKey(userId)){
            users.put(userId,HashSet<Int>());
        }
        feedList.add(Pair(userId,tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    fun getNewsFeed(userId: Int): List<Int> {
        val newsFeed:MutableList<Int> = mutableListOf<Int>();

        for(index in feedList.lastIndex downTo 0){
            var feed = feedList[index];
            if(newsFeed.size==10){
                break;
            }

            if(feed.first == userId || (users.containsKey(userId) && users.get(userId)!!.contains(feed.first))){
                newsFeed.add(feed.second);
            }
        }

        return newsFeed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    fun follow(followerId: Int, followeeId: Int) {
        if(!users.containsKey(followerId)){
            users.put(followerId,HashSet<Int>());
        }
        users.get(followerId)!!.add(followeeId)
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    fun unfollow(followerId: Int, followeeId: Int) {
        if(!users.containsKey(followerId)){
            return
        }

        users.get(followerId)!!.remove(followeeId);
    }

}
