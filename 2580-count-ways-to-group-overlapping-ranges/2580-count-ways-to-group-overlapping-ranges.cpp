class Solution {
public:
    int mod=1e9+7;
    int countWays(vector<vector<int>>& ranges) {
        int cnt=1;
        int n=ranges.size();
        if(n==1) return 2;
        sort(ranges.begin(),ranges.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1]<ranges[i][0]){
                ans.push_back(ranges[i]);
            }else{
                ans.back()[1]=max(ans.back()[1],ranges[i][1]);
            }
        }
        int g=ans.size();
        while(g){
            cnt=(cnt*2)%mod;
            g--;
            
        }
        return cnt;
    }
};