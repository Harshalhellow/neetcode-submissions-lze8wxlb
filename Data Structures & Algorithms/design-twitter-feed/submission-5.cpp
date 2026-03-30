class Twitter {
public:
unordered_map<int,vector<int>>usertofollowers;
unordered_map<int,vector<pair<int,int>>>userstotweets;
int time = 0;

    Twitter() {
        // a hashmap of users to vector of followers
// a hashmap to a users to a priority que of pairs of tweets with time and tweet id max up to 10
// time global
    }
    
    void postTweet(int userId, int tweetId) {
        userstotweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>mostrecenttweets;
        for(int i=0; i<userstotweets[userId].size(); i++){
            mostrecenttweets.push(userstotweets[userId][i]);
            if(mostrecenttweets.size()>10) mostrecenttweets.pop();
        }
        for(int i=0; i<usertofollowers[userId].size(); i++){
            for(int j=0; j<userstotweets[usertofollowers[userId][i]].size(); j++){
                mostrecenttweets.push(userstotweets[usertofollowers[userId].at(i)].at(j));
                if(mostrecenttweets.size()>10) mostrecenttweets.pop();
            }
        }
        vector<int> answer;
        int n = mostrecenttweets.size();
        for(int i=0; i<n; i++){
            answer.push_back(mostrecenttweets.top().second);
            mostrecenttweets.pop();
        }
        reverse(answer.begin(),answer.end()); 
        return answer;

        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId&& find(usertofollowers[followerId].begin(),usertofollowers[followerId].end(),followeeId)==usertofollowers[followerId].end()) usertofollowers[followerId].push_back(followeeId); return;
        
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){ 
        auto it = find(usertofollowers[followerId].begin(), usertofollowers[followerId].end(), followeeId); 
        if(it!=usertofollowers[followerId].end())usertofollowers[followerId].erase(it);
        }
    }
};

