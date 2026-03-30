class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,pair<int,int>>> maxheap;
        for(int i=0; i<points.size(); i++){
            float distance = sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            maxheap.push({distance,{points[i][0],points[i][1]}});
            if(maxheap.size()>k) maxheap.pop();

        } 
        vector<vector<int>> answer;
        int size = maxheap.size();
        for(int i=0; i<size; i++){
            vector<int> points;
            points.push_back(maxheap.top().second.first);
            points.push_back(maxheap.top().second.second);
            answer.push_back(points);
            maxheap.pop();
        }
        return answer;

    }
};


// we just create a max heap of size k remove
// 