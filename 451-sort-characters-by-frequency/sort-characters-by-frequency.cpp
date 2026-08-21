class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        string ans="";
        priority_queue<pair<int,char>>pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto it =pq.top();
            int t=it.first;
            char c=it.second;
            while(t--){
                ans+=c;
            }
            pq.pop();
        }
        return ans;
    }
};