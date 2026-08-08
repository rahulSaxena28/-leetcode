class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int dis;
        priority_queue<pair<int,vector<int>>>pq;
        for(auto it : points){
            int x=it[0];
            int y=it[1];
            dis=x*x+y*y;
            pq.push({dis,{x,y}});
            while(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};