class Solution {
public:
    void solve(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp){
        if(i>=nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,ans,temp);
        temp.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        solve(i+1,nums,ans,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans,temp);
        return ans;
    }
};