class Solution {
public:
    void solve(int idx,vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp,int &sum,int &target){
        if(sum>=target || idx>=nums.size()){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[idx]);
        sum+=nums[idx];
        solve(idx+1,nums,ans,temp,sum,target);
        sum-=nums[idx];
        temp.pop_back();
        while(idx<nums.size()-1 && nums[idx]==nums[idx+1])idx++;
        solve(idx+1,nums,ans,temp,sum,target);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum=0;
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,ans,temp,sum,target);

        return ans;
    }
};