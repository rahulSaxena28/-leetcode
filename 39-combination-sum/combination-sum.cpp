class Solution {
public:
    void solve(int i,vector<int> &nums,int &target,vector<vector<int>>&ans,vector<int> &temp,int &sum){

        if(sum>=target || i==nums.size()){
            if(sum==target) ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        sum+=nums[i];
        solve(i,nums,target,ans,temp,sum);
        sum-=nums[i];
        temp.pop_back();

        solve(i+1,nums,target,ans,temp,sum);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum=0;
        solve(0,candidates,target,ans,temp,sum);
        return ans;
    }
};